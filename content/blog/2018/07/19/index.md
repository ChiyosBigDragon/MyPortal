---
title: "SRM500 Div1Easy MafiaGame"
date: 2018-07-19T12:00:00+09:00
draft: false
tags: ["SRM","Math","Simulation"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=11342

## 概略
このゲーム，言語化が難しい．

- $N$ 人には0-indexedで番号が振られている．また`vulnerable`には最初 $N$ 人全員がいる．
- 以下の手順でゲームは進行する．

1. `vulnerable`内で $N$ 票を振り分ける．
    1. `vulnerable&&decisions`の人は`decisions`で宣言された分だけ得票する．
        - `vulnerable={0,1,3}`，`decisions={0,1,1,2}`の場合，`0`は1票，`1`は2票を得る．`2`は`vulnerable`に含まれないので得票しない．
    1. 上で $k$ 票消費されたとする．余った $N-k$ 票は得票数の最小値が大きくなるよう，均等に振り分ける．
        - 5人の得票数が`{1,0,3,2,1}`で残り5票ある場合，以下のように分ける．
        - `{1,0,3,2,1}`→`{1,1,3,2,1}`(1票消費)→`{2,2,3,2,2}`(4票消費)→`{3,2,3,2,2}`(5票消費)
        - ただし5票目に選ばれる人物は2票得ている者の中からランダム
1. 票数の最も大きい者のみが`vulnerable`に残る．
1. `vulnerable`が1人になるまで投票を繰り返す．最後に残った1人が敗者となる．

各人が敗者となる確率を $p[i]$ としたときの $\max p$を計算する．なお，ゲームが終わらない場合には0を返す．

## 方針
「ゲームが終わらない」というのは，ゲーム中のある時点で`vulnerable`のサイズが不変，つまり`vulnerable`内の得票数が全て等しくなるということである．この判定法は投票の回数で異なる．

- 投票1回目
    - `vulnerable`には $N$ 人全員がいるので，`decisions`に複数現れる人物がいない場合，全員の得票数は1となってループ.
- 投票2回目以降
    - `decisions`に係る投票を終えた時点で，`vulnerable`内の得票数は等しい（そういう風に投票1回目で分けます）．残りの票を振り分けたときに同票であるとループする．`vulnerable`のサイズを $i$ とするとループの条件は、$N\equiv 0\pmod i$

ループの条件がわかったのでシミュレーションができる．敗者は1回目の投票後に`vulnerable`にいる人のいずれかであり，彼らに区別はない．よって確率は、$1/i$

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/500Div1E_MafiaGame.cpp" >}}
