---
title: "SRM503 Div1Easy ToastXToast"
date: 2018-07-31T16:00:00+09:00
draft: false
tags: ["SRM","Ad hoc"]
topics: ["CompetitiveProgramming"]
---

## URL
http://community.topcoder.com/stat?c=problem_statement&pm=11204

## 概略
$N$ 種のパンについての情報`under`と`over`が与えられる．各種のパンには $X_i$ が定められており，これより小さいパンは`under`，大きいパンは`over`である．$\min N$ はいくらであるか．条件を満たすパンが存在しない場合`-1`を返す．

## 方針
最初サンプル3の意味がわからなくて焦った.

1列に並べた時に

- 左端に`over` || 右端に`under`
    - そんなパンはないので，`-1`
- `under`と`over`が完全に分かれている
    - Xがその間に置けて，`1`
- その他
    - 下図より，`2`（のはず）

![][toast]

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/503Div1E_ToastXToast.cpp" >}}

[toast]: ./images/toast.png
