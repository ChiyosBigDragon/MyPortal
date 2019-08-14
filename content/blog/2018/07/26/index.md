---
title: "SRM501 Div1Easy FoxPlayingGame"
date: 2018-07-26T17:30:00+09:00
draft: false
tags: ["SRM","Math","Greedy"]
topics: ["CompetitiveProgramming"]
---

## URL
http://community.topcoder.com/stat?c=problem_statement&pm=11284

## 概略
初期スコアを0として2種類の行動を任意の順番で行う．

- A: `scoreA`を足す．
- B: `scoreB`を掛ける

Aを $nA$ 回，Bを $nB$ 回行うときのスコアの最大値を求める．

## 方針
[1年生 (A First Grader) &mdash; Aizu Online Judge][1年生] を解いた経験からDP解を思いつくも，うまくいかない．しぶしぶ考察すると，「足してから掛けたい」「正負は融通が利くので絶対値を大きくしたい」など思いついたため，全部入れ込んだ．場合分けはコードを参照．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/501Div1E_FoxPlayingGame.cpp" >}}

追記：他人の解法が鮮やかすぎて直視できない

[1年生]: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0557
