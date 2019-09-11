---
title: "SRM655 Div1Easy BichromePainting"
date: 2019-09-11T12:00:00+09:00
draft: false
tags: ["SRM", "Greedy"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=13709

## 概略
グリッドに色を塗る操作を行う．最初は全て白である．1回の操作では，$k \times k$ の正方形を選び，その中を黒または白で塗りつぶす事ができる．この操作を任意回繰り返すとき，与えられる最終的な色の配置が実現できるかどうかを調べる．

## 方針
最終状態から操作を逆にたどってみることにします．今戻すことができるのは $k \times k$ が全て同じ色で塗られている箇所です．問題は戻したあとの盤面がどうなっているかです．「戻す」操作は，順方向から見れば「塗りつぶす」操作であることに注意します．「塗りつぶす」際に重要なことは，その下の色などどうでも良いということです．つまり「戻す」操作における遷移先は，黒と白のどちらもとることができます．便宜上これを `D` と置くと，全てのマスを`D`にできるかという問題に変化し，これはシミュレーションすれば良いです．$n \leq 20$ なので何でもできます．実装は $O(n^6)$ です．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/640-659/655Div1E_BichromePainting.cpp" >}}

## 反省
`D`はDottidemoiiのD．