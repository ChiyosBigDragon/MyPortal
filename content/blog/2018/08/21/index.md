---
title: "SRM504.5 Div1Easy TheNumbersWithLuckyLastDigit"
date: 2018-08-21T20:00:00+09:00
draft: false
tags: ["SRM","Math"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=11096

## 概略
$n$ が与えられる．$n$ を下1桁が $4$ または $7$ である正の数の和として表すとき，必要な項数の最小はいくつであるか．構成不可能であれば `-1` を返す．

## 方針
$4+10k,7+10k$ を使うことが出来るので，$n$ が項数 $x$ で構成可能であるとき，$n+10k$ も項数 $x$ で構成可能．したがって $n$ の下1桁に注目してやればいい．

例えば下1桁が $3$ になるような項数最小の構成法は
$$
23 = 4 \times 4 + 7 \times 1
$$
である．これを下1桁 $0 \sim 9$ についてやればよく，結果下図が完成した．

<center>
    {{< figure src="./images/sum.png" >}}
    <figcaption>4と7で表せる数の下一桁</figcaption>
    {{< figure src="./images/minimum.png" >}}
    <figcaption>最小値未満の数は表せない</figcaption>
</center>

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/504.5Div1E_TheNumbersWithLuckyLastDigit.cpp" >}}
