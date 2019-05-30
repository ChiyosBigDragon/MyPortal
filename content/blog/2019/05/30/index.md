---
title: "SRM759 Div1Easy EllysThreePrimes"
date: 2019-05-30T10:00:00+09:00
draft: false
tags: ["SRM","Brute Force"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=15436

## 概略
5桁の素数 $A, B, C$ がある．各桁の和が与えられるので，これを満たす $(A, B, C)$ の組を1つ求める．ただし $A, B, C$ は**互いに異なる**．

## 方針
$A, B$ を決め打つ全探索がしたくなる．5桁なので $O(n^2)$ は怪しいが，色々工夫すると通る．

主な枝刈りは以下の通り．手元で1s前後．

- エラトステネスの篩で $A, B$ の候補を絞る．
- $A < B$ とする．
- $C$ の1桁目は偶数でも $5$ でもないので，そこで探索を打ち切る．
- $C$ の最上位は $0$ ではないので，そこでも探索を打ち切る．
- $C$ の素数判定は篩の中を二分探索する．（これは怪しい）

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/740-759/759Div1E_EllysThreePrimes.cpp" >}}

## 反省
どう頑張っても1sかかるので，ジャッジを信じて投げたら通った．あとでシステスを通したら最大で400msだった．信仰心が足りない．
