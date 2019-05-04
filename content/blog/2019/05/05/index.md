---
title: "Google Code Jam 2019 - Round 1C"
date: 2019-05-05T06:00:00+09:00
draft: false
tags: ["GCJ","WriteUp"]
topics: ["CompetitiveProgramming"]
---

- [QualのWriteUp](../../04/07)
- [R1AのWriteUp](../../04/13)
- [R1BのWriteUp](../../04/29)
- [R1CのWriteUp](../05/05)

# 結果
AB2完60pt．414th．なんかstraightforwardでした．ゲームを直前までしてたのがよかったのかも．

# A: Robot Programming Strategy
## 概略
手順のわかっている[ジャンケンマン](https://ja.wikipedia.org/wiki/%E3%82%B8%E3%83%A3%E3%83%B3%E3%82%B1%E3%83%B3%E3%83%9E%E3%83%B3_(%E3%82%A2%E3%83%BC%E3%82%B1%E3%83%BC%E3%83%89%E3%82%B2%E3%83%BC%E3%83%A0))がたくさんいるので，全員にワンコインで勝てる「対ジャンケンマンロボ」を作ろう．

## 雑感
今残っているジャンケンマン全部に，勝ちまたはあいこが出せればいい．実装ゲー．

今気付いたけど *googol* って $10^{100}$ じゃん．血の気が引いた．翻訳に投げたのをそのまま読んで`10100`を書いている．実際には1手で1台倒すはずだからこんなにループはいらないし，むしろ $A$ が大きかったらTLEだった．昨日のAGCもそうだが，よく嘘をついてしまう．

{{< code language="cpp" src="./code/a.cpp" >}}

# B: Power Arrangers
## 概略
`{A,B,C,D,E}`の順列 $120$ セットが1列に並んでいる．はずだったが1セット抜けているらしい．何回かの質問でどのセットが抜けているかを特定しよう．

## 雑感
最初に各セットの先頭を質問すると候補が1/5に減って，残りの各セットの2番目を質問すると候補が1/4に減って…．これはAを解いてたら自然な流れだと思う．

そう思うからこそ，Largeの質問回数を計算してたまげる．
$$ 150 \geq 148 = 119 + 23 + 5 + 1 = 119 + \left( \dfrac{120}{5} - 1 \right) + \left( \dfrac{24}{4} - 1 \right) + \left( \dfrac{6}{3} - 1 \right) $$

流石にテストがしたいので`testing_tool.py`をDLする．やっぱり使い方がわからない．名前付きパイプとかを使うのだと思うが，どうやら違うらしい．しょうがないので答えが`ABCDE`になるケースを自分で作ってテストした．相変わらずひどい．

{{< code language="cpp" src="./code/b.cpp" >}}

# C: Bacterial Tactics
## 概略
縦または横に拡散するバクテリアでゲームをします．

## 雑感
障害物のないものはどこかで解いたことある気がする．そのときは分割後の長方形についてメモ化再帰をした気がする．するだけでなにもわからない．適当な全探索がバグってサンプルも通らず終了．

# 感想
後でちゃんと調べたら，インタラクティブには`interactive_runner.py`が別に存在して，それにコマンドとかも書いてあった．こんなんで落ちてたらシャレにならない．

あと1勝でTシャツ．コンテストTシャツはちょいモテファッションだと植松晃士も言っているはず．欲しい．

これすき

<iframe width="560" height="315" src="https://www.youtube.com/embed/PGJlH4RP0CQ" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
