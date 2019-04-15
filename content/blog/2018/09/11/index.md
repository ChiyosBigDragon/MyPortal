---
title: "SRM512 Div1Easy MysteriousRestaurant"
date: 2018-09-11T09:00:00+09:00
draft: false
tags: ["SRM","Greedy"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=11295

## 概略
$N$ 日間だけ開くレストランがある．メニューは $M$ 種類あり，その値段は日ごと，メニューごとに異なる．

また，注文するメニューは $7$ 日前と同じでなくてはならない．

1日1回注文をするとして，財布の限り粘るとすると何日間粘ることが出来るか．

## 方針
サンプル1を見ると，1日だけいる場合と8日いる場合とでは，取る料理の種類が異なることがわかる．なので日を進めるたび，曜日( $7n$ 日前)の料理をおさらいして最小コストを再計算してやるとよい．

7日目まではソートして一番左にくるやつを選ぶ．以降は曜日でかかったコストをいったん`budget`に戻してから再計算．この方法だと貪欲にやってる感が強いので見通しはいい．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/512Div1E_MysteriousRestaurant.cpp" >}}
