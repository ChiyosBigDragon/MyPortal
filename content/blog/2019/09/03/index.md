---
title: "SRM656 Div1Easy RandomPancakeStack"
date: 2019-09-03T12:00:00+09:00
draft: false
tags: ["SRM", "DP"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=13747&rd=16416

## 概略
大きさの異なるパンケーキをランダムに積む．自分より小さいパンケーキの上には積むことができず，積めなくなった時点で美味しさの総和が計算される．総和の期待値を求める．

## 方針
`dp[i][j] := 一番上の大きさがiで既にj個積んでいる確率`とします．パンケーキは大きい順に見ると遷移が簡単です．

個数が $j$ で一番上が $k$ である山に積む場合を考えます．パンケーキ $i$ を引く確率は $\dfrac{1}{n - j}$ なので，`dp[i][j + 1]`について，$\sum_{k}^{i - 1}$  `dp[k][j] / (n - j)`です．

また $i$ を積む場合の確率はこれで網羅できていることになるので，その期待値は $\sum_{j}$ `dp[i][j] * d[i]`です．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/640-659/656Div1E_RandomPancakeStack.cpp" >}}

## 反省
確率DPは配るDPのほうが良いと思っているのに，なんで貰うDPにしたのか謎．