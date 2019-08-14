---
title: "SRM500 Div2Easy SRMCards"
date: 2018-07-18T12:00:00+09:00
draft: false
tags: ["SRM","Greedy"]
topics: ["CompetitiveProgramming"]
---

## URL
http://community.topcoder.com/stat?c=problem_statement&pm=11341

## 概略
数列が空になるまで以下の操作を繰り返す．

- 数列から1つ数字を選びこれを消す．
- 上で選んだ数字を $n$とするとき，数列に $n\pm 1$ が存在すればこれ(ら)も同時に消す．

取り得る操作回数のうち最大を求める．

## 方針
ソートして小さい順に選択すると最大．証明は苦しいが，3個同時に消せる場面では必ず2-1と2回に分けて消せることに注意する．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/500Div2E_SRMCards.cpp" >}}
