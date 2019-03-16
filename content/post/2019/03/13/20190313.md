---
title: "Node.jsで作る番組情報通知Bot"
date: 2019-03-13T18:00:00+09:00
draft: false
topics: ["Programming"]
tags: ["Node.js", "Slack"]
---

<p><!--more--></p>
## 先に
この記事は下記事の内容をパクったと言っても過言ではありません．

<iframe class="hatenablogcard" style="width:100%;height:155px;max-width:680px;" title="Node.jsでテレビの映画放映情報をWebスクレイピングしてSlackに通知する" src="https://hatenablog-parts.com/embed?url=https://blog.honjala.net/entry/2018/09/13/004442" width="300" height="150" frameborder="0" scrolling="no"></iframe>

もはや写経ですが勉強記録用なので．

## 動機
時の流れか，我が家では4月から新聞の購読を停止することになりました．非常に残念であります．かくいう私も，新聞をまともに読んでいたのはGコードが消えるか否かのころまでだったと思います．今ではラテ欄とスポーツ欄に隔月で発生する大相撲ぐらいしか読んでいません．あと下世話な週刊誌の広告．

テレビっ子な私はラテ欄の代替を探さなければならないわけですが，Webの番組表の扱いにくさは厳しいものがあります．あの縦長どうにかなりませんか．あの中で見たい番組を探すのは至難の技でしょう．こんな状態なので最低限，自分が興味のある番組くらいは抑えておきたいわけです．スクレイピングはPythonでかじっているので苦労はしないと思うのですが．

## 流れ
- [手作業でのURL取得](#手作業でのURL取得)
- [スクレイピングと整形](#スクレイピングと整形)
- [Slackへの通知](#Slackへの通知)
- [実行](#実行)

## 手作業でのURL取得
[番組を探す &mdash; Gガイド.テレビ王国][検索]で見たい番組のキーワードや芸能人の名前を入力しURLを生成します．ここ一番ダサいです．試しに`地上波`+`金属バット`[^1]で検索します．

`https://tv.so-net.ne.jp/schedulesBySearch.action?condition.genres[0].parentId=-1&condition.genres[0].childId=-1&stationPlatformId=1&condition.keyword=%E9%87%91%E5%B1%9E%E3%83%90%E3%83%83%E3%83%88&submit=%E6%A4%9C%E7%B4%A2&descriptive=true`

このURLとページのソースを元にスクレイピングしていきます．`url.json`には後で使う情報を入れておきます．
### url.json
```json
{
    "list": [
        {
            "id": "地上波+金属バット",
            "url": "https://tv.so-net.ne.jp/schedulesBySearch.action?condition.genres%5B0%5D.parentId=-1&condition.genres%5B0%5D.childId=-1&stationPlatformId=1&condition.keyword=%E9%87%91%E5%B1%9E%E3%83%90%E3%83%83%E3%83%88&submit=%E6%A4%9C%E7%B4%A2&descriptive=true"
        },
        {
            "id": "スカパー！+ゲームセンターCX",
            "url": "https://tv.so-net.ne.jp/schedulesBySearch.action?stationPlatformId=5&condition.keyword=%E3%82%B2%E3%83%BC%E3%83%A0%E3%82%BB%E3%83%B3%E3%82%BF%E3%83%BCCX&submit=%E6%A4%9C%E7%B4%A2&descriptive=true"
        }
    ]
}

```

## スクレイピングと整形
### TV_scrape.js
```js
const httpClient = require('cheerio-httpcli');

async function fetch(url) {
    const baseUrl = url;
    const scheduleList = [];
    const result = await httpClient.fetch(baseUrl);
    const $ = result.$;
    $('.utileList', '.contBlockNB').each(function () {
        const row = $(this);
        scheduleList.push({
            title: $('h2 a', row).text().trim(),
            date: $('.utileListProperty', row).text().trim().replace(/([\s\t\n]|&nbsp;)+/g, ' '),
            caps: $('.utileListDetail', row).text().trim(),
        });
    });
    return scheduleList;
}

function stringifyList(scheduleList) {
    return scheduleList.map(schedule => stringify(schedule)).join('\n\n');
}

function stringify(schedule) {
    let text = schedule.date + '\n';
    text += '*' + schedule.title + '*' + '\n';
    text += '>' + schedule.caps + '\n';
    return text;
}

module.exports = {
    fetch,
    stringifyList,
    stringify
}
```
### メモ
- ライブラリは`cheerio-httpcli`を使う．`require`は`import`みたいなものだろうか．
- 関数名の前に`async`を置くと内部で`await`が使える．`await`は待機と例外処理を担う？
- `index`側から`fetch`にURLを投げる．
- タグはそのまま，`id`は`#`，`class`は`.`を付けて表現する．
- `module.exports`は外から呼んだときに使えるようにするもの？

## Slackへの通知
### slack.js
```js
const request = require('request');

module.exports = {
    postMessage: async (token, channel, text) => {
        const options = {
            headers: {
                'Authorization': 'Bearer ' + token
            },
            form: {
                channel: channel,
                text: text,
                as_user: true
            },
            json: true
        };
        return new Promise((resolve,reject) => {
            request.post('https://slack.com/api/chat.postMessage', options, (error, res, body) => {
                if(error) {
                    reject(error);
                }
                resolve({
                    response: res,
                    body: body
                });
            });
        });
    }
};
```
### メモ
- 一言一句違わず申し訳ない気持ちになる．
- やっていることは単純だが一から書くとなると…

### index.js
通知といったら瓦版なのでチャンネル名は`#瓦版`です．`fetch`の前に`await`を入れないとエラーを吐くので気を付けます(1敗)．
```js
const slack = require('./slack');
const TVScrape = require('./TV_scrape');
const fs = require('fs');

function main() {
    const jsonObject = JSON.parse(fs.readFileSync('./url.json', 'utf8'));
    jsonObject.list.forEach(async (obj) => {
        const scheduleList = await TVScrape.fetch(obj.url);
        const scheduleListText = TVScrape.stringifyList(scheduleList);
        const slackMessageText = '*<' + obj.id + ' の番組情報>*\n\n' + scheduleListText;
        const token = 'API_TOKEN';
        slack.postMessage(token, '#瓦版', slackMessageText);
    });
}

main();
```

## 実行
```sh
node index.js
```

{{% fluid_img src="../images/capture.png" %}}
<center><figcaption>#角界のロボコップ</figcaption></center>
小さいかもしれませんね．すみません．

## 他にやりたいこと
- AWSで定期的に実行．
- Slackの`slash-command`を用いた検索条件の追加削除．

今回はここまで．

[ブログ]: https://blog.honjala.net/entry/2018/09/13/004442
[検索]: https://tv.so-net.ne.jp/search/
[wiki]: (https://ja.wikipedia.org/wiki/%E9%87%91%E5%B1%9E%E3%83%90%E3%83%83%E3%83%88_(%E3%81%8A%E7%AC%91%E3%81%84%E3%82%B3%E3%83%B3%E3%83%93)
[^1]: [金属バット (お笑いコンビ) &mdash; Wikipedia][wiki]
