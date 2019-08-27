---
title: "SRM730 Div1Easy StonesOnATree"
date: 2019-08-27T12:00:00+09:00
draft: false
tags: ["SRM", "DP", "Graph Theory"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=14811

## 概略
有向木の頂点に石を置いていくゲームを行う．葉には無条件で置いてよい．親に置くためには，その直接の子すべてに石が置かれていなければならない．また，任意のタイミングで石を取り除くことができる．根に石を置いた時点でゲームは終了する．

各頂点には重み $w$ が付いている．石が置かれている頂点 $i$ について $W = \sum w_i$ が逐一計算され，ゲームのスコアは $\max W$ である．スコアの最小値を求める．

## 方針
操作を先読みしたいときにはメモ化再帰が有効です．

`dp[i] := iに石を置く操作をするときのスコアの最小値`とします．頂点`i`の子が`L`，`R`であるとき，`i`に石を置く操作には以下の工程が考えられます．

1. `L`に石を置く
   - `dp[L]`
2. `R`に石を置く
   - `dp[R]`
3. `L`に石を置く操作を一通り行った後，`R`に置く操作を行う．またはその逆．これは小さい方を選択できる．
   - `min(w[L] + dp[R], w[R] + dp[L])`
4. `L`と`R`の両方に石が置かれていて，`i`に石を置く
   - `w[i] + w[L] + w[R]`

`dp[i]`はこのうちの最大値を取ります．子が0, 1つの場合も同様に計算できます．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/720-739/730Div1E_StonesOnATree.cpp" >}}

## 反省
操作順を親と子の重みだけで評価できると思って時間を溶かす．そんなわけない．