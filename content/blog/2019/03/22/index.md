---
title: "SRM753 Div1Easy MaxCutFree"
date: 2019-03-22T14:00:00+09:00
draft: false
tags: ["SRM", "Graph Theory", "Independent Set", "DP"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=15257

## 概略
単純無向グラフ $G$ が与えられる．$G$ の[橋][bridge]を含まないような[誘導部分グラフ][induced subgraph]のうち，頂点数が最大となるものを求める．

## 方針
要は，$G$ から橋だけを残したグラフについての[最大独立集合問題][independent set]である．このグラフは明らかに[森][forest]であるから，木DPが使える．

### 参考
<iframe src="https://hatenablog-parts.com/embed?url=http%3A%2F%2Ftatanaideyo.hatenablog.com%2Fentry%2F2015%2F04%2F26%2F182621" style="border: 0; width: 100%; height: 190px;" allowfullscreen scrolling="no" allow="autoplay; encrypted-media"></iframe>

制約が甘いので橋の検出にはUnionFindを使う．各辺ごとにそれを除いたグラフを構築し，端点の連結性を判定する．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/740-759/753Div1E_MaxCutFree.cpp" >}}

## 反省
本番では橋の検出までしかできなかった．最大独立集合問題であることにはなんとなく気付いていたが，名前だけが先走った．「NP困難じゃん…」

`dp`等の初期化も忘れずに．

[bridge]: https://ja.wikipedia.org/wiki/%E9%80%A3%E7%B5%90%E3%82%B0%E3%83%A9%E3%83%95#%E8%BE%BA%E9%80%A3%E7%B5%90%E5%BA%A6
[induced subgraph]: https://ja.wikipedia.org/wiki/%E3%82%B0%E3%83%A9%E3%83%95%E7%90%86%E8%AB%96#%E9%83%A8%E5%88%86%E3%82%B0%E3%83%A9%E3%83%95%E3%81%A8%E6%8B%A1%E5%A4%A7%E3%82%B0%E3%83%A9%E3%83%95
[independent set]: https://ja.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E7%8B%AC%E7%AB%8B%E9%9B%86%E5%90%88%E5%95%8F%E9%A1%8C
[forest]: https://ja.wikipedia.org/wiki/%E6%9C%A8_(%E6%95%B0%E5%AD%A6)
