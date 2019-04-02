---
title: "LCA (Lowest Common Ancestor)"
draft: false
---

# 概略
根付き木における2頂点の共通祖先のうち，最も深いものを示す．

# 目次
- [アルゴリズム](#アルゴリズム)
    - [Euler Tour](#euler-tour)
    - [RMQ (Range Minimum Query)](#rmq-range-minimum-query)
- [計算量](#計算量)
- [実装例](#実装例)
- [verify](#verify)
    - [AOJ GRL_5_C](#AOJ GRL_5_C)
    - [ABC014_D](#ABC014_D)
- [参考](#参考)

# アルゴリズム
Euler Tourで木に対する情報を拾った後，RMQでLCAを求める．

例として下図の木にアルゴリズムを用いる．

![](../images/tree.png)

## Euler Tour
木をDFSする．欲しい情報は以下の通り．

- `nodeOrder[i]`: $i$ 番目に訪問した頂点番号
- `depthOrder[i]`: $i$ 番目に訪問した頂点の深さ（根を0とする）
- `nodeFirstID[v]`: 頂点 $v$ が最初に現れるタイミング

$i$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14
:---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---:
`nodeOrder[i]` | 0 | 1 | 4 | 1 | 5 | 6 | 5 | 7 | 5 | 1 | 0 | 2 | 0 | 3 | 0
`depthOrder[i]` | 0 | 1 | 2 | 1 | 2 | 3 | 2 | 3 | 2 | 1 | 0 | 1 | 0 | 1 | 0

$v$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
:---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---:
`nodeFirstID[v]` | 0 | 1 | 11 | 13 | 2 | 4 | 5 | 7

`nodeOrder`のサイズは必ず`頂点数*2-1`になる．これは各辺を2回通ることに由来する．

## RMQ (Range Minimum Query)
頂点 $u$ と $v$ のLCAは，$u$ から $v$ まで順に訪問した頂点のうち最も浅い（深さの小さい）ものである．これを効率的に求めるのがRMQである．

頂点 $4$ と $7$ のLCAを求める．まず頂点の訪問順を調べる．

<style type="text/css">
    .tg .tg-c4ww{background-color:#cbcefb;}
    .tg .tg-bolj{background-color:#ffccc9;}
</style>
<table class="tg">
  <tr>
    <th class="tg-c3ow">$v$<br></th>
    <th class="tg-c3ow">0</th>
    <th class="tg-c3ow">1</th>
    <th class="tg-c3ow">2</th>
    <th class="tg-c3ow">3</th>
    <th class="tg-bolj">4<br></th>
    <th class="tg-c3ow">5</th>
    <th class="tg-c3ow">6</th>
    <th class="tg-c4ww">7</th>
  </tr>
  <tr>
    <td class="tg-c3ow">`nodeFirstID[v]`</td>
    <td class="tg-c3ow">0</td>
    <td class="tg-c3ow">1</td>
    <td class="tg-c3ow">11</td>
    <td class="tg-c3ow">13</td>
    <td class="tg-bolj">2<br></td>
    <td class="tg-c3ow">4<br></td>
    <td class="tg-c3ow">5</td>
    <td class="tg-c4ww">7</td>
  </tr>
</table>

したがって $4$ と $7$ のLCAは以下の色付き部分のうち最も浅い頂点であり，今回は $1(i=3)$ であることが分かる．

<style type="text/css">
    .tg{text-align:center;}
    .tg .tg-bolj{background-color:#ffccc9;}
    .tg .tg-nly6{background-color:#f5ccd4;}
    .tg .tg-bhmg{background-color:#eacdde;}
    .tg .tg-wspl{background-color:#e0cde8;}
    .tg .tg-8vju{background-color:#d6cef2;}
    .tg .tg-sh07{background-color:#cbcefb;}
</style>
<table class="tg">
  <tr>
    <th class="tg-c3ow">$i$<br></th>
    <th class="tg-c3ow">0</th>
    <th class="tg-c3ow">1</th>
    <th class="tg-bolj">2</th>
    <th class="tg-nly6">3</th>
    <th class="tg-bhmg">4<br></th>
    <th class="tg-wspl">5</th>
    <th class="tg-8vju">6</th>
    <th class="tg-sh07">7</th>
    <th class="tg-baqh">8</th>
    <th class="tg-baqh">9</th>
    <th class="tg-baqh">10</th>
    <th class="tg-baqh">11</th>
    <th class="tg-baqh">12</th>
    <th class="tg-baqh">13</th>
    <th class="tg-baqh">14</th>
  </tr>
  <tr>
    <td class="tg-c3ow">`nodeOrder[i]`</td>
    <td class="tg-c3ow">0</td>
    <td class="tg-c3ow">1</td>
    <td class="tg-bolj">4</td>
    <td class="tg-nly6">1</td>
    <td class="tg-bhmg">5</td>
    <td class="tg-wspl">6</td>
    <td class="tg-8vju">5</td>
    <td class="tg-sh07">7</td>
    <td class="tg-baqh">5</td>
    <td class="tg-baqh">1</td>
    <td class="tg-baqh">0</td>
    <td class="tg-baqh">2</td>
    <td class="tg-baqh">0</td>
    <td class="tg-baqh">3</td>
    <td class="tg-baqh">0</td>
  </tr>
  <tr>
    <td class="tg-c3ow">`depthOrder[i]`</td>
    <td class="tg-c3ow">0</td>
    <td class="tg-c3ow">1</td>
    <td class="tg-bolj">2</td>
    <td class="tg-nly6">1</td>
    <td class="tg-bhmg">2</td>
    <td class="tg-wspl">3</td>
    <td class="tg-8vju">2</td>
    <td class="tg-sh07">3</td>
    <td class="tg-baqh">2</td>
    <td class="tg-baqh">1</td>
    <td class="tg-baqh">0</td>
    <td class="tg-baqh">1</td>
    <td class="tg-baqh">0</td>
    <td class="tg-baqh">1</td>
    <td class="tg-baqh">0</td>
  </tr>
</table>

# 実装例

- LCA( $V,root,edge$ ) := 頂点数 $V$，根 $root$ の根付き木 $edge$ に対する，EulerTourとRMQの構成．
    - $O(V)$
- get( $u,v$ ) := 頂点 $u$ と $v$ のLCAを求める．
    - $O(\log{V})$

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/GraphTheory/LCA/LCA.cpp" >}}

# verify
<h4 id="AOJ GRL_5_C"><a href="https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C">LCA: Lowest Common Ancestor - GRL_5_C &mdash; AIZU ONLINE JUDGE</a></h4>

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/GraphTheory/LCA/verify/GRL_5_C.cpp" >}}

<h4 id="ABC014_D"><a href="https://atcoder.jp/contests/abc014/tasks/abc014_4">D: 閉路 - AtCoder Beginner Contest 014 &mdash; AtCoder</a></h4>

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/GraphTheory/LCA/verify/ABC014_D.cpp" >}}

# 参考
- [Lowest common ancestor &mdash; Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor)
- <a target="_blank" href="https://www.amazon.co.jp/gp/product/4839941068/ref=as_li_tl?ie=UTF8&camp=247&creative=1211&creativeASIN=4839941068&linkCode=as2&tag=chiyosbigdrag-22&linkId=951fa29af799762ef87abd1933093da4">プログラミングコンテストチャレンジブック [第2版]　～問題解決のアルゴリズム活用力とコーディングテクニックを鍛える～</a><img src="//ir-jp.amazon-adsystem.com/e/ir?t=chiyosbigdrag-22&l=am2&o=9&a=4839941068" width="1" height="1" border="0" alt="" style="border:none !important; margin:0px !important;" />
    - P.294 ~
- [LCA and RMQ ~簡潔もあるよ！~ &mdash; SlideShare](https://www.slideshare.net/yumainoue965/lca-and-rmq)
- [前処理O(n)クエリO(1)のLCAと静的RMQ &mdash; ｼﾞｮｲｼﾞｮｲｼﾞｮｲ](http://joisino.hatenablog.com/entry/2017/08/13/210000)
