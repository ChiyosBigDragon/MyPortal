---
title: "SRM681 Div1Easy FleetFunding"
date: 2019-08-20T12:00:00+09:00
draft: true
tags: ["SRM", "Greedy", "Binary-Search"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=14104

## 概略
宇宙船1隻を作るには，$m$ 種類のパーツが1つずつ必要である．また，店が $n$ 個ある．店 $i$ は種類 $[a[i], b[i]]$ のパーツを合計 $k[i]$ 個まで売ってくれる．

宇宙船は最大何隻作れるか．

## 方針
$x$ 隻作れるかを二分探索する．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/680-699/681Div1E_BearCries.cpp" >}}
