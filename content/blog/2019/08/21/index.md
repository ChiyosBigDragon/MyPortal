---
title: "SRM681 Div1Easy FleetFunding"
date: 2019-08-21T12:00:00+09:00
draft: false
tags: ["SRM", "Greedy", "Binary Search"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=14104

## 概略
宇宙船1隻を作るには，$m$ 種類のパーツが1つずつ必要である．また，店が $n$ 個ある．店 $i$ は種類 $[a_i, b_i]$ のパーツを合計 $k_i$ 個まで売ってくれる．

宇宙船は最大何隻作れるか．

## 方針
$x$ 隻作れるかを二分探索します．判定にはパーツの種類を時間軸に持った，区間スケジューリング的な考え方を用います．パーツの種類を昇順に見ていき，現時点で購入可能な店について $b_i$（区間の上限）の昇順に合計 $x$ 個購入します．途中で購入可能な店が無くなった場合，失敗です．このような操作は優先度付きキューを2本持つことで簡単に実現できます．

パーツの総数は $\sum k \leq nk _ {\max}$ なので操作回数は大体 $m \log \dfrac{n}{m}k _ {\max}$ で，これはおよそ $10^6$ です．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/680-699/681Div1E_FleetFunding.cpp" >}}
