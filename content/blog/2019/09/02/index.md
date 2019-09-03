---
title: "SRM654 Div1Easy SquareScores"
date: 2019-09-02T12:00:00+09:00
draft: false
tags: ["SRM", "Brute Force"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=13694&rd=16318

## 概略
`?`を含む文字列が与えられる．同じ文字種のみを含む連続部分文字列の個数がスコアとなる．`?`が確率 $P_i$ で変化するとき，スコアの期待値を求める．

## 方針
文字種`c`と左端 $L$ を固定します．左端が $L$ である連続部分文字列の個数は $L$ から右に伸ばしていくことで $O(|S|)$ で求まります．期待値の線形性から，途中で`?`が来る場合には $P_c$ を乗じれば良く，これを全文字種，全左端で行って $O(|P||S|^2)$．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/640-659/654Div1E_SquareScores.cpp" >}}
