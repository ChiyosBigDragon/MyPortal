---
title: "SRM668 Div1Easy PaintTheRoom"
date: 2019-09-12T12:00:00+09:00
draft: false
tags: ["SRM", "Math"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=13846&rd=16548

## 概略
$R \times C$ のマス全てをちょうど $K$ 回だけ通るような一筆書きの経路は存在するか？

## 方針
$K = 1$ で巡回路が作れれば，$K > 1$ についても構築可能です．巡回できないケースは $R$ と $C$ の両方が奇数の場合のみです．これが真に構築不能であることの証明ができなかったので参考リンクを貼っておきます．

- 巡回路ができないことの証明
  - <a href=http://kmjp.hatenablog.jp/entry/2014/12/05/0900>yukicoder : No.85 TVザッピング(1) &mdash; kmjp's blog</a>
- 構築不能であることの証明
  - <a href=http://kmjp.hatenablog.jp/entry/2015/09/17/0900>TopCoder SRM 668 Div1 Easy PaintTheRoom &mdash; kmjp's blog</a>

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/660-679/668Div1E_PaintTheRoom.cpp" >}}

## 反省
そこそこ自信はあったが証明はできていないので，本番ですぐに提出できるかは微妙．