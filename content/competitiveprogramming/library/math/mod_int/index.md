---
title: "ModInt"
draft: true
---

https://topcoder.g.hatena.ne.jp/spaghetti_source/20130126/1359171466

A' = |a 1 0|
     |b 0 1|
を
S A' = |g x y|
       |0 u v|
まで変形するということは
       |a s -|
       |b t -|
を初期値a=x,b=mod,s=1,t=0からb=0になるまで変形するということ．

http://noshi91.hatenablog.com/entry/2019/03/31/174006
https://ei1333.github.io/luzhiled/snippets/math/mod-int.html

friendを付ける意味
http://www7b.biglobe.ne.jp/~robe/cpphtml/html02/cpp02043.html
cin>>int>>mod や cout<<mod は
左項がmodintではないのでクラス外から呼び出す必要がある．しかしそれだとprivateであるmod.xにアクセスできないのでfriendで解決する．
publicだったらいらなくね?
