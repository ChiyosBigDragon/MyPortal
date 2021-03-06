---
title: "ブログ記事中のスニペットを外部参照する"
date: 2019-03-27T10:00:00+09:00
draft: false
topics: ["Programming"]
tags: ["jQuery", "HTML"]
---

{{< code language="cpp" src="./sample.cpp" >}}

上を表示するためのHTMLは次の通りです．

```html
<pre><code class="language-cpp" src="./sample.cpp"></code></pre>
```

端的には`<pre><code>`に`src`属性を追加します．

## 動機
最近はもっぱらラップトップでブログを書くわけですが，画面が小さく[^1]，エディタとプレビューでいっぱいいっぱいになってしまいます．こんな状態でスニペットを含むMarkdownを開いた光景は，JR武蔵小杉駅の南武線ホームを彷彿とさせます．

スニペットを省略できれば全体の見通しが良くなることはもちろん，メンテナンス性の向上(?)も期待されます．どっかの数学者も言ってましたね．「ソースコードは分割せよ」って．

## 流れ
- [jQueryを読み込む](#jQueryを読み込む)
- [DOMの書き換え](#DOMの書き換え)
- [Markdown](#Markdown)

## jQueryを読み込む
今回はjQueryを使うことにします．`<head>`内で読み込み．

```html
<head>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
<head>
```

## DOMの書き換え
{{< code language="js" src="https://raw.githubusercontent.com/ChiyosBigDragon/chiyosbigdragon.github.io/master/js/srcReader.js" >}}

### メモ
- `index`と書いたが実際は何を指しているのか不明．なんだろう．

## Markdown
今回の記事のソースコードはこんな感じ．

```markdown
    ---
    title: "ブログ記事中のスニペットを外部参照する"
    date: 2019-03-27T10:00:00+09:00
    draft: false
    topics: ["Programming"]
    tags: ["jQuery", "HTML"]
    ---

    <pre><code class="language-cpp" src="./sample.cpp"></code></pre>

    上を表示するためのHTMLは次の通りです．

    ```html
    <pre><code class="language-cpp" src="./sample.cpp"></code></pre>
    ```

    端的には`<pre><code>`に`src`属性を追加します．

    ## 動機
    最近はもっぱらラップトップでブログを書くわけですが，画面が小さく[^1]，エディタとプレビューでいっぱいいっぱいになってしまいます．こんな状態でスニペットを含むMarkdownを開いた光景は，JR武蔵小杉駅の南武線ホームを彷彿とさせます．

    スニペットを省略できれば全体の見通しが良くなることはもちろん，メンテナンス性の向上(?)も期待されます．どっかの数学者も言ってましたね．「ソースコードは分割せよ」って．

    ## 流れ
    - [jQueryを読み込む](#jQueryを読み込む)
    - [DOMの書き換え](#DOMの書き換え)
    - [Markdown](#Markdown)

    ## jQueryを読み込む
    今回はjQueryを使うことにします．`<head>`内で読み込み．

    ```html
    <head>
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <head>
    ```

    ## DOMの書き換え
    <pre><code class="language-js" src="https://raw.githubusercontent.com/ChiyosBigDragon/chiyosbigdragon.github.io/master/js/srcReader.js"></code></pre>

    ### メモ
    - `index`と書いたが実際は何を指しているのか不明．なんだろう．
```

本当はHugoのshortcode機能を使ってさらに楽するつもりだったが，そこまで変わらなかった．拡張子の抽出ができればいいのだが．

ひたすら楽してブログラミング

[^1]: 12.5インチ
