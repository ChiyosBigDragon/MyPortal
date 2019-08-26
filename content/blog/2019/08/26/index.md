---
title: "SRM659 Div1Easy ApplesAndOrangesEasy"
date: 2019-08-26T12:00:00+09:00
draft: false
tags: ["SRM", "Greedy"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=13791&rd=16462

## 概略
果物（リンゴまたはオレンジ）を順に $N$ 個食べる．`info[i]`番目は必ずリンゴを食べる．直近 $K$ 個の内，リンゴは最大でも $\left\lfloor \dfrac{K}{2} \right\rfloor$ 個までしか食べてはいけないとき，全体で食べるリンゴの最大値を求める．

## 方針
左から見ていき，リンゴを食べられるならば必ず食べる貪欲をします．$i$ 番目にリンゴを食べるとその影響は $i + K - 1$ 番目まで及ぶため，後回しにして同じ個数を食べられる可能性はあっても，それより多く食べることはできません（？）．

あとは $i$ 番目でリンゴが食べられるかを判定できればよく，これは全ての $0 \leq d < K$ について $[i - d, i + (K - d))$ に含まれるリンゴが $\left\lfloor \dfrac{K}{2} \right\rfloor$ 個未満であることが条件です．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/640-659/659Div1E_ApplesAndOrangesEasy.cpp" >}}

## 反省
貪欲の証明があっているのかわからない．脳死でセグ木を貼らない．