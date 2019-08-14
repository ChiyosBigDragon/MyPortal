---
title: "SRM502 Div1Easy TheLotteryBothDivs"
date: 2018-07-27T21:30:00+09:00
draft: false
tags: ["SRM","Math"]
topics: ["CompetitiveProgramming"]
---

## URL
http://community.topcoder.com/stat?c=problem_statement&pm=11359

## 概略
`"000000000"`～`"999999999"`のうち，`goodSuffixes`を含むものを当たりとするときの当選確率を求める．

## 方針
単純に数えると重複が生じることに気を付ける．集合を意識すると良い．

- `goodSuffixes={"47","4747"}`とすると，`"4747"`$\subset$`"47"`なので`"4747"`を数える必要はない．

そこで`goodSuffixes`を桁数の小さい順に並べて，集合の大きい方のみを数えるようにする．

追記: 昔のコード酷すぎるな．`while`のくだりは`used`かなんかで管理したほうが絶対良い．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/502Div1E_TheLotteryBothDivs.cpp" >}}

テストおわったのでしっかり精進します
