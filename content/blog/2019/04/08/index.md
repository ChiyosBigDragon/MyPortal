---
title: "BeautifulSoup4で某番組HPをスクレイピング"
date: 2019-04-08T23:00:00+09:00
draft: false
tags: ["Python","BeautifulSoup4"]
topics: ["Programming"]
---

今回は[ここのページ](http://www.ntv.co.jp/anothersky/fashion/)をスクレイピングします．使途未定ですが，同一人物の写真が大量にあるので解析に使えるかもしれないし使えないかもしれない．

春の番組改編でリニューアルしてましたけど何にも変わってなかったですね．でもホームページだけは変わってるんですよ．古いページは任天堂[^1]を除いて十中八九消される運命なので救出しなければなりません．すでにバナー消えてたし．

# 解析

```
http://www.ntv.co.jp/anothersky/fashion/index.html
http://www.ntv.co.jp/anothersky/fashion/index_2.html
http://www.ntv.co.jp/anothersky/fashion/index_3.html
…
http://www.ntv.co.jp/anothersky/fashion/index_25.html
```

```html
<div class="entryBox clearfix">
  <div class="img">
    <img src="画像1">
  	<img src="画像2">
  </div>
  <div class="entryBody">
    <h3>日付</h3>
    <p>詳細</p>
  </div>
</div>
```

another skyの雰囲気良いですよね．シンプルで洗練された印象があります．一つ気に食わない点があって，ワイプが斜めなんですよ．そこだけ変に立体感があってゴチャっと見えるというか．惜しい．

# スクレイピング

```python
def scrape(soup) :
    pages = soup.find_all(class_='entryBox clearfix')
    for page in pages :
        div = page.find(class_='entryBody')
        # 日付取得
        date = ''.join(div.find('h3').text.split())
        dir = './data/' + date + '/'
        os.mkdir(dir)
        # 詳細取得
        details = div.find('p').text
        with open(dir + str('details.txt'), 'w', encoding='utf-8') as file :
            file.write(details)
        # 画像取得
        imgs = page.find_all('img')
        cnt = 0
        for img in imgs :
            src = requests.get(img['src'])
            with open(dir + str(cnt).zfill(3) + str('.jpg'), 'wb') as file :
                file.write(src.content)
                cnt += 1
```

金曜夜ってのも良いですね．肩の力を抜いて見ることが出来るので．another skyとタモリ倶楽部を見ることで僕の一週間に区切りが付きます．

# 全体

```python
import re
import requests
from bs4 import BeautifulSoup
import os
import shutil

def scrape(soup) :
    # 省略

def main():
    # dataディレクトリ作成
    if os.path.isdir('./data') :
        shutil.rmtree('./data')
    os.mkdir('./data')
    # URL生成
    for page in range(1,26) :
        url = 'http://www.ntv.co.jp/anothersky/fashion/index'
        if page > 1 :
            url += '_' + str(page)
        url += '.html'
        res = requests.get(url)
        content = res.content
        soup = BeautifulSoup(content, 'html.parser')
        # スクレイピング
        scrape(soup)

if __name__ == '__main__' :
    main()
```

「ここが私のアナザースカイ」は一度言ってみたい台詞上位に食い込んでいます．

# 結果
流石に載せられないのでディレクトリツリーを書きます．

```
data
│  ├─2016.10.07OA
│  │ ├─000.jpg
│  │ ├─001.jpg
│  │ └─details.txt   
│  ├─2016.10.14OA
│  ├─2016.10.21OA
│  ├─2016.10.28OA
…
```

[^1]: この会社マジですごいと思う．当時のバーチャルボーイのページを見るやつなんて誰がいるんだ．
