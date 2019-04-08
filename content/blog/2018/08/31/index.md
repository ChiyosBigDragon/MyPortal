---
title: "SRM510 Div1Easy TheAlmostLuckyNumbersDivOne"
date: 2018-08-31T13:30:00+09:00
draft: true
tags: ["SRM","Digit DP"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=11461

## 概略
$[a,b]$ の整数のうち，$4,7$ 以外の数を2つ以上含まないものは何種類あるか．

## 方針
求めるものは
$$b以下の種類数 - (a-1)以下の種類数$$
と解釈することが出来る．

そこで次のDPテーブルを定義する．
$$
dp(n)[i][0/1][k][0/1] := nを上からi桁目まで見て/n以下が確定し/4,7以外の個数kで/i桁目までに0以外の数が出現する/ような種類数
$$
すると解は
$$
dp(b)[|b|][1][0/1][1] - dp(a-1)[|a-1|][1][0/1][1]
$$
で表される．ただし $|n|$ は $n$ の10進表記における桁数．


{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/510Div1E_TheAlmostLuckyNumbersDivOne.cpp" >}}
