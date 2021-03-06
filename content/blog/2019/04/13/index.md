---
title: "Google Code Jam 2019 - Round 1A"
date: 2019-04-13T15:00:00+09:00
draft: false
tags: ["GCJ","WriteUp"]
topics: ["CompetitiveProgramming"]
---

- [QualのWriteUp](../07)
- [R1AのWriteUp](../13)
- [R1BのWriteUp](../29)
- [R1CのWriteUp](../../05/05)
- [R2のWriteUp](../../05/19)

## 結果
aC2完45pt．1500人通過で~~1584th~~1567th(何故か上がった)でした．まさかペナ差で落ちるとは…

## A: Pylons
### 概略
$R\times C$のグリッドを後述するルールで動く駒がある．重複することなく全てのマスを踏めるならば，その動き方を示せ．

### ルール
移動前の座標を $(r,c)$ ，移動後の座標を $(r',c')$ とする．以下のいずれにも該当してはいけない．

- $r = r'$
- $c = c'$
- $r - c = r' - c'$
- $r + c = r' + c'$

### 雑感
全探索しかわからない．最初はSmallすらも落ちたが，1解に到達した時点で強制終了させたらなんとか通った．Largeはまったくわからない．桃色大戦ぱいろんは昔やってましたね．

{{< code language="cpp" src="./code/a.cpp" >}}

## B: Golf Gophers
### 概略
風車の羽根の枚数を毎晩いじって，ゴルフ場に棲むGopherの数を推定しよう．

### 雑感
残り30分を切ったころに読み始めた．インタラクティブで絶望．この時点で2完なのでSmallだけでもとりたい気持ち．SmallはGopherの数が少ないので，雑でも行けると思って書き始めたがTLE．風車は回らず，Qualのツケが回ってきた．今考えれば中国剰余だなあという感じ．みんなのGOLFは4を昔やってましたね．

## C: Alien Rhyme
### 概略
与えられた単語からrhymeできるもの同士をペアにしたとき，最大何組ペアが出来るか．ただし同じ位置でのrhymeはありえんライムなのでやってはいけません．

### 雑感
後ろから見て共通する部分で木を作った．これを「trie木」と言うらしい．深さが1進むと，その位置でrhymeするペアを1組作れるので，作れるペアの数を返り値で管理してDFSした．共通部分が長いとペアの数が単語数を超えるので，きちんと`min`を取らないといけない．`substr`しまくったので計算量が不安だったがなんとかLargeも通った．バイオ4[^1]は昔やってましたね．

{{< code language="cpp" src="./code/c.cpp" >}}

## 感想
あとの2回で通る気がしません．繰り上げとか，なさらないんですか？

[^1]: [バイオ4空耳 完全版 &mdash; YouTube][バイオ4]
[バイオ4]: https://youtu.be/bseJZEgPa04?t=25
