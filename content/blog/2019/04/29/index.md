---
title: "Google Code Jam 2019 - Round 1B"
date: 2019-04-29T06:00:00+09:00
draft: false
tags: ["GCJ","WriteUp"]
topics: ["CompetitiveProgramming"]
---

- [QualのWriteUp](../07)
- [R1AのWriteUp](../13)
- [R1BのWriteUp](../29)
- [R1CのWriteUp](../../05/05)

# 結果
Ac2完41pt．~~1815th~~．1811st．やっぱりちょっと上がりますね．Round1Cに進出．

# A: Manhattan Crepe Cart
## 概略
より多くの人が向かう交差点の場所を特定しよう．

## 雑感
$(x,y)$ にいる人が $+x$ 方向を向いているなら交差点の候補は $(x',y') (x+1 \leq x' \leq Q, 0 \leq y' \leq Q)$

点の候補が $x,y$ について独立なので別々に求めることが出来る．集計はimos法が楽か．何故か配列を4つ用意してさらに添字ミスで1WA．

{{< code language="cpp" src="./code/a.cpp" >}}

# B: Draupnir
## 概略
X-day ringはX日で倍に増える．$d$ 日目のリングの総数を質問できるので，0日目での各リングの数を求めよう．

## 雑感
$W = 2$ って何．Smallであれば連立1次方程式を解くだけでいいのでネットに実装を探しに行く．Python+ガウスの消去法が見つかったので慣れないながらもやる．手元では合ったのにWAした．辛い．

Editorialにあった実装．

{{< code language="cpp" src="./code/b.cpp" >}}

# C: Fair Fight
## 概略
$$
\left| \max _ {l \leq i \leq r} {c[i]} - \max _ {l \leq j \leq r} {d[j]} \right| \leq K
$$

をみたす $[l,r]$ の組数．

## 雑感
いやLargeなに．周りの様子的にみんなも解けてなさそうなので，セグ木貼るだけのSmallを通す．この作戦は実際悪くなく，通した時点で400thぐらいだった．悔しいなあ．

{{< code language="cpp" src="./code/c.cpp" >}}

# 感想
$\sum{(rank-1500)}$ だったら1500th以内だと思うのでそれでどうにかなりませんか．
