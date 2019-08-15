---
title: "SRM757 Div1Easy CentipedeSocks"
date: 2019-08-15T12:00:00+09:00
draft: false
tags: ["SRM", "Greedy"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=15445&rd=17496

## 概略
足が $F$ 本のムカデが $C$ 匹いる．それぞれのムカデはすべての足に同じ色の靴下を履かないと満足しない．靴下はビンに入っていて，各色の本数の内訳は`vector`で示される．ビンからランダムに靴下を取り出していき，同色が $F$ 本揃った時点でムカデに履かせる．

すべてのムカデが満足するためにビンから取り出す靴下の本数の最大値を求める．

## 方針
最終的にできるだけ多くの靴下を無駄にしたいです．そこで次のような貪欲を考えます．

<div align="center">「残りの本数から $F$ 本取ったあとに追加で取れる本数の多い順に取る」</div>

わかりづらいので実装したアルゴリズムを使って，適当な入力を処理します．あとは頑張ってください．

`F = 5, s(sockCounts) = {1, 3, 6, 7, 10, 14}`とします．


1. `F`に満たないものを全部取ります．
   - `ans += 1 + 3`
   - `s = {6, 7, 10, 14}`
2. `s`をソートして貪欲に取っていきます．ルールは「`F`本取ったあとに追加で取れる本数の多い順に取る」です．括弧内が指標です．`F`本取れる場合にはカウント`C`が減っていきます．今回は`C = 5`とします．
   1. `{14(4), 10(4), 7(2), 6(1)}`
   2. `{10(4), 9(4), 7(2), 6(1)}`
      - `C = 4`
      - `ans += 5`
   3. `{9(4), 5(4), 7(2), 6(1)}`
      - `C = 3`
      - `ans += 5`
   4. `{5(4), 4(4), 7(2), 6(1)}`
      - `C = 2`
      - `ans += 5`  
   5. `{4(4), 7(2), 6(1)}`
      - `C = 1`
      - `ans += 5`  
   6. `{7(2), 6(1)}`
      - `C = 1`
      - `ans += 4`  
   7. `{2(2), 6(1)}`
      - `C = 0`
      - `ans += 5`
3. 最後に取ったもの以外を処理します．ムカデが満足しているのでもう靴下は要りません．
   1. `2`
      - さっき取りました．
   1. `6`
      - `ans += 4`
4. おわり

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/740-759/757Div1E_CentipedeSocks.cpp" >}}