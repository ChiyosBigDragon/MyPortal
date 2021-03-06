---
title: "SRM506 Div1Easy SlimeXSlimesCity"
date: 2018-08-16T03:30:00+09:00
draft: false
tags: ["SRM","Greedy"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=11154

## 概略
$N$ 個の街があり各々には名前がついている．2つの街の合併を繰り返し，最終的に1つにすることを考える．

合併前の街の人口を $i,j (i \leq j)$ とする．

- $i < j$ のとき
    - 合併後の街の名前は $j$ を継承する．
- $i = j$ のとき
    - 合併後の街の名前は $i$ または $j$ を継承する．

最終的に街が1つになったとき，その名前として取り得るものは何通りか．

## 方針
~~[B - Colorful Creatures &mdash; AtCoder Grand Contest 011](https://atcoder.jp/contests/agc011/tasks/agc011_b)~~

サンプル5の解釈を説明する．

![](./images/merge.png)

ソートして人口の昇順に並べても一般性は失われない．また赤は累積和である．

合併のルールから，自分より人口の少ない街は無条件に取り込めるので全て取り込むことにする．これで増えた人口でも1つ右の街が取り込めなければ，その街が生き残ることはない．最終目標は全ての街を合併することなので，右から赤と黒を判定をしていき，図の点線のように断層ができるまでの数が答え．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/506Div1E_SlimeXSlimesCity.cpp" >}}
