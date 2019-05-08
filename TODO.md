## ページレイアウト
- 今更気付いたけど`<h1>`のフォントデカすぎ．とりあえず`<h2>`以下で作って．
- [x] タイトル
    - サーチはしやすくなりましたか?
    - 短めかつサーチしやすいように
    - サブは **Der Pinguin werft das Fenster mit dem Apfel ein.** でよくないか?
    - 左上に置くか，サイドバーに置くか
- [ ] トップページ
    - ABCD…ってやったら綺麗だよね．
        - サイドバーがHomeから始まるからHABCDSでもいいかも
    - [ ] About
    - [x] Blog
        - 最新5件ぐらい表示させたら
    - [ ] CompetitiveProgramming
    - [ ] どっち
        - [ ] Deutsch
        - [ ] Diary
    - [ ] Sumo
    - [ ] Product
        - ないけど
- [x] カテゴリ/タグ
    - 押したあとの題字が **Srm** とかになるの気に食わない
    - `config.toml` に以下を記述
        ```toml
        preserveTaxonomyNames = true
        ```
- [ ] シンタックスハイライト
    - AtCoderみたいにしたい
    - **google-code-prettify** を使っている?
    - [x] スクロール
    - [ ] 展開ボタン
    - [ ] (任意)ファイル名
    - [x] 外部参照
        ```html
        <pre><code class="language-xxx" src="url.xxx"></code></pre>
        ```
        - 一応shortcodeも書いてみたが全然楽になっていない．`src`から拡張子を抜き出せたら多分楽になる．
        ```
        {{< code language="xxx" src="url.xxx" >}}
        ```
- [ ] Read More
    - いらない
    - Postsぐらい簡潔でいい
- [ ] ブログカード
    - [iframely](https://iframely.com/) 使うのが丸い?
    - markdownにhtml置くのアレだけどしょうがない
- [ ] 被共有
    - [ ] faviconの作成
    - [ ] 記事ごとのサムネイル設定
        - ないときはfaviconに近いやつ
    - [ ] SNSの共有ボタン
- [x] Disqus
    - [ ] とりあえず入れたけど日本語化できない
        - 現行verを翻訳しないとプルダウンメニューに日本語が出ないっぽい．
        - 何度か確認して．
    - 登録するの面倒だな
    - コメント書くひといるかな
- [ ] アクセスカウンター
    - [【ajax-counter】Ajaxによるアクセスカウンタを作ったので公開します](https://shirokai.hatenablog.com/entry/ajax-counter)
- [ ] スマホ対応
    - 多分トップページがやばい
- [ ] アフィ
    - そりゃ金は欲しいけどやるわけなくないか
    - 尼のやつは置いてもそんなに不快ではない(?)
    - 干し芋が理想だけどそこまでの実績がありません

## 個別ページ
- [ ] ブログ
    - はてなの移植を早急に
- [ ] 競プロ
    - [ ] ライブラリ
    - [ ] ツール

## katex
- 表示できないときはとりあえず切り分けて，字間にスペースを入れまくる
- 行列を複数行で表示できない
    - library/math/matrix
    - 改行がバックスラッシュ3個なのもきつい
