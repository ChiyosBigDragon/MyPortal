## ページレイアウト
- [x] タイトル
    - サーチしやすくなりましたか?
    - 短めかつサーチしやすいように
    - サブは **Der Pinguin werft das Fenster mit dem Apfel ein.** でよくないか?
    - 左上に置くか，サイドバーに置くか
- [ ] トップページ
    - [ ] About
    - [ ] Product
        - ないけど
    - [x] Blog
        - 最新5件ぐらい表示させたら
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
- [ ] アクセスカウンター
    - [【ajax-counter】Ajaxによるアクセスカウンタを作ったので公開します](https://shirokai.hatenablog.com/entry/ajax-counter)
