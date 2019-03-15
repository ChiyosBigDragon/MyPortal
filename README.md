# MyPortal
https://chiyosbigdragon.github.io/<br>

以下はあとで関数化しましょう

```sh
cd MyPortal
```

## ページ作成
```sh
hugo new post/$1.md --editor="atom"
```

## ページビュー
```sh
hugo server -D -w -t blackburn
```
- `-D`: 下書きあり
- `-w`: リアルタイム
- `-t + theme`: テーマ反映

## ソース保存
```sh
cd public
git add .
git commit -m "msg"
git push origin master
```

## デプロイ
```sh
cd public
git add .
git commit -m "msg"
git push origin master
```

## 参考
- [HUGOでブログ作成 → GitHub Pagesで公開する手順 &dash; chanmitsu55 blog](https://chanmitsu55.github.io/2017/12/25/2017-12-25-create-blog-by-hugo/)
    - この通りにやれば良い．サブモジュール化はいいぞ．
- [Hugo + GitHub Pages で新ブログを開設した話 &dash; ラング・ラグー](https://blog.wtsnjp.com/2016/11/23/hugo/#fnref:hl)
    - あとで色々設定するときに読む．
- [Hugoで新規記事を作成するときのTips的なメモ &dash; Qiita](https://qiita.com/n0bisuke/items/4701481c3bca4df81b0b)
    - これも
