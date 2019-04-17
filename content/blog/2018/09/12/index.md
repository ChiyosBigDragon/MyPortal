---
title: "SRM513 Div1Easy YetAnotherIncredibleMachine"
date: 2018-09-12T09:00:00+09:00
draft: true
tags: ["SRM","Greedy","未完"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=11502

## 概略
https://www.gog.com/game/the_incredible_machine_mega_pack
https://store.steampowered.com/app/241240/Contraption_Maker/?l=japanese

## 方針
サンプル1を見ると，1日だけいる場合と8日いる場合とでは，取る料理の種類が異なることがわかる．なので日を進めるたび，曜日( $7n$ 日前)の料理をおさらいして最小コストを再計算してやるとよい．

7日目まではソートして一番左にくるやつを選ぶ．以降は曜日でかかったコストをいったん`budget`に戻してから再計算．この方法だと貪欲にやってる感が強いので見通しはいい．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/513Div1E_YetAnotherIncredibleMachine.cpp" >}}
