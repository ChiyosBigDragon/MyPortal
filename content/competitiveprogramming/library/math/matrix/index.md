---
title: "Matrix"
draft: true
---

# 概略
行列計算

# 目次
- [アルゴリズム](#アルゴリズム)
- [実装例](#実装例)
- [verify](#verify)
    - [ABC009_D](#ABC009_D)
- [参考](#参考)

# アルゴリズム

# 実装例

# verify
<h4 id="ABC009_D"><a href="https://atcoder.jp/contests/abc009/tasks/abc009_4">D - 漸化式 - AtCoder Beginner Contest 009 &mdash; AtCoder</a></h4>

$$
    \begin{array}{ccc}
        \left(
            \begin{array}{ccc}
                  A_{N+K} \\
                  A_{N+K-1} \\
                  A_{N+K-2} \\
                  \vdots \\
                  A_{N+1}
            \end{array}
        \right)
        &=&
        \left(
            \begin{array}{ccc}
                  C_1 & C_2 & \ldots & C_{K-1} & C_K \\
                  1 & 0 & \ldots & 0 & 0 \\
                  0 & 1 &  \ldots & 0 & 0 \\
                  \vdots & \vdots & \ddots & \vdots & \vdots \\
                  0 & 0 & \ldots & 1 & 0
            \end{array}
        \right)
        \left(
            \begin{array}{ccc}
                  A_{N+K-1} \\
                  A_{N+K-2} \\
                  A_{N+K-3} \\
                  \vdots \\
                  A_{N}
            \end{array}
        \right) \\
        &=&
        \left(
            \begin{array}{ccc}
                  C_1 & C_2 & \ldots & C_{K-1} & C_K \\
                  1 & 0 & \ldots & 0 & 0 \\
                  0 & 1 &  \ldots & 0 & 0 \\
                  \vdots & \vdots & \ddots & \vdots & \vdots \\
                  0 & 0 & \ldots & 1 & 0
            \end{array}
        \right)^N
        \left(
            \begin{array}{ccc}
                  A_{K} \\
                  A_{K-1} \\
                  A_{K-2} \\
                  \vdots \\
                  A_{1}
            \end{array}
        \right) \\
    \end{array}
$$

ANDの単位元が`UINT_MAX`であることに注意．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Matrix/verify/ABC009_D.cpp" >}}

# 参考
- [パスカルの三角形 &mdash; Wikipedia](https://ja.wikipedia.org/wiki/%E3%83%91%E3%82%B9%E3%82%AB%E3%83%AB%E3%81%AE%E4%B8%89%E8%A7%92%E5%BD%A2)
- [1~nまでの逆元をO(n)で求める方法 &mdash; takapt0226's diary](http://takapt0226.hatenablog.com/entry/2013/03/15/213551)
- [よくやる二項係数 (nCk mod. p)、逆元 (a^-1 mod. p) の求め方 &mdash; けんちょんの競プロ精進記録](http://drken1215.hatenablog.com/entry/2018/06/08/210000)
- [nCr mod mの求め方 &mdash; uwicoder](https://www37.atwiki.jp/uwicoder/pages/2118.html)
- [コウメ太夫 (@dayukoume) &mdash; Twitter](https://twitter.com/dayukoume)

https://ei1333.github.io/luzhiled/snippets/math/matrix.html
http://www.learning-algorithms.com/entry/2017/10/13/193130
https://emtubasa.hateblo.jp/entry/2018/09/07/131441
https://yukicoder.me/problems/no/194
https://yukicoder.me/problems/no/194
