---
title: "SRM505 Div2Medium PerfectSequences"
date: 2018-08-14T14:30:00+09:00
draft: false
tags: ["SRM","Math"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=11397

## 概略
`perfect sequence` とは以下の条件をともに満たす数列である．

- 全要素が非負整数
- 全要素の積と和が等しい

`seq` の要素をひとつだけ変更して `perfect sequence` が作れるかを判定する．

## 方針
$$
S_i = \frac {\sum_k{seq[k]}} {seq[i]}
$$
$$
P_i = \frac {\prod_k{seq[k]}} {seq[i]}
$$
とすれば，`perfect sequence`が作れる時
$$
S_i + x = T_i \times x ⇔ S_i = (T_i - 1) \times x
$$
をみたす $x$ が1つ以上の $i$ で存在する．

ただし以下の点に注意．

- 変更しないのはダメ．
- `seq` のサイズが1なら必ず `Yes`
- $T_i - 1 = 0$ のとき0除算で危ない．この場合， $S_i = 0$ であればよい。

最悪のケースだと $T_i \approx 10 ^ {9 \times 50}$になってオーバーフローするからこのコードはダメなはず…だけど，普通に通る．

あえて対処するなら，実行時間に余裕があるので一つ一つ $T_i$ を計算するべき．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/505Div2M_PerfectSequences.cpp" >}}
