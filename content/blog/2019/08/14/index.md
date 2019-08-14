---
title: "SRM715 Div1Easy MaximumRange"
date: 2019-08-14T12:00:00+09:00
draft: false
tags: ["SRM", "Greedy"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=14613

## 概略
`+`，`-`からなる文字列がある．`+`はインクリメント，`-`はデクリメントに相当する．初期値を0として左から操作を行い，操作中の最大値と最小値の差がスコアになる．

与えられた文字列の部分列についても同様に操作が行えるとき，スコアの最大値はいくらであるか．

## 方針
`+`または`-`のみを取ることで簡単にスコアを最大化できます．最大値と最小値のペアを $(\max, \min)$ と表すことにします．`+`のみが $A$ 個ある操作列は $(A, 0)$ で，スコアは $A$ です．ここに`-`を $B$ 個加えてみましょう．スコアを上げるには最小値を小さくするしかなく，相殺する位置には置けません．

- 先頭に加えたとき : $(\max(A - B, 0), -B)$
  - スコア : $\max(A, B)$
- 殿に加えたとき : $(A, \min(A - B, 0))$
  - スコア : $\max(A, B)$

が考えられますが，これは結局，`+`または`-`のみを取れば良いことを示しています．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/700-719/715Div1E_MaximumRange.cpp" >}}
