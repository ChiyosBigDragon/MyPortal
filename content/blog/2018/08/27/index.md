---
title: "SRM509 Div1Easy LuckyRemainder"
date: 2018-08-27T22:30:00+09:00
draft: false
tags: ["SRM","Math"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=11138

## 概略
$N$ 桁の整数 $X$ が与えられる．$super(X)\pmod {9}$ を求める．ただし，$super(X)$ とは $X$ の部分列の総和である．

### ex)
$$
super(123) = 123 + 12 + 13 + 23 + 1 + 2+ 3 = 177
$$

## 方針
$n\times 10^k\equiv n\times 1^k\equiv n\pmod 9$ なので，$super(X)$ を求める過程で各桁の数字が何回出現するかを数えればいい．

$X[i]$ (0-indexed)が出現する回数は，$X[i]$ より左側から $l$ 個，右側から $r$ 個取るとして
$$
\sum _ {l=0} ^ {i} \sum _ {r=0} ^ {N-1-i} {}_{i} \mathrm{C} _ {l} \times {} _ {N-1-i} \mathrm{C} _ {r}
$$
で表される．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/509Div1E_LuckyRemainder.cpp" >}}
