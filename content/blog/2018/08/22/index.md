---
title: "SRM508 Div1Easy DivideAndShift"
date: 2018-08-22T16:30:00+09:00
draft: false
tags: ["SRM","Brute Force"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=11434

## 概略
$1 \sim N$ のスロットが1列に並んでいる．プレイヤーは常にスロット $1$ の中身しか取得することができない．ゲームの目的は，開始時にスロット $M$ にあった中身を取得することである．

スロットには2通りの操作を行うことが出来る．

- `Divide`
    - $N$ を割り切れる素数 $p$ を選びスロットを $[1,\frac{N}{p}],[\frac{N}{p}+1,\frac{2N}{p}],…$ に分割する．この内，目的のスロットを含む部分列のみを保持する．その後，$N←\frac{N}{p}$とし，スロットの番号を $1 \sim \frac{N}{p}$ に振り直す．
- `Shift`
    - スロットを左/右にシフトする．シフトするとスロット番号が $-1/+1$ だけ変化する．スロット $0$ は $N$ に，$N+1$ は $1$ に別途移動する．

最低で何回操作をすれば目的を達成できるか．

## 方針
全然できなかった．調べたら「`Divide`と`Shift`の操作は可換」ということがわかって（証明は知らない）そこからはノーヒントで行けた．これで250ptなんだ…

`Shift`は数えるだけなので先に`Divide`を行う．`Divide`のやり方は高々、`2^(素因数の数)`だから全列挙してやればいい．あとは各々について`Shift`の回数を求める．

のんきに数えてたらTLEしたので，剰余で考える必要があるのだが，これが難しかった．右に`Shift`する場合の式がよくわからなくて，手元のサンプルと帳尻を合わせるように書いたら通った（最悪）

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/508Div1E_DivideAndShift.cpp" >}}
