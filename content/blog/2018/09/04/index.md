---
title: "SRM510 Div2Medium TheLuckyGameDivTwo"
date: 2018-09-04T19:00:00+09:00
draft: false
tags: ["SRM","Brute Force"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=11464

## 概略
`Lucky number`は $4,7$ のみを含む数字である．

JohnとBrusはゲームをする．先ずJohnが長さ`jLen`の区間を選ぶ．そのあとBrusが長さ`bLen`の区間を「Johnが選んだ区間」の中から選ぶ．Brusが選んだ区間に含まれる`Lucky number`の数がポイントになる．

Johnがスコアを最大化するように，Brusがスコアを最小化するように戦術をとるとき，最終的なスコアはいくらになるか．

## 方針
範囲が $[1,4747]$ と狭いので全探索できそう．

Johnはスコアが大きくなるように，Brusはスコアが小さくなるように，それぞれ区間をとるというのがわかりにくい．こういう戦略最適化問題の場合，おおむね先手はエスパーなので，まずBrusの行動から考える．

BrusはJohnの決めた区間のうち，スコアが小さくなるよう更に区間を定める．つまり，Johnの各選択に対してスコアは一意に確定することがわかる．こうなると後は単純で，Johnはこの内スコアが最も大きくなる選択をすればいい．数学でやる1文字固定に近い．

どうせラッキーナンバーは少ないので，2進数を列挙する感覚で全部書き出した．春に受講した，ひたすらカルノー図を書く授業を思い出してちょっと鬱になった．

Brusが全範囲の最小値を必死に探す中，Johnはそのうちの最大値を高みの見物で選ぶ．そんな主従関係が目に浮かぶと書きやすいですね．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/510Div2M_TheLuckyGameDivTwo.cpp" >}}
