---
title: "Matrix"
draft: false
---

# 概略
行列計算

# 目次
- [アルゴリズム](#アルゴリズム)
- [実装例](#実装例)
- [verify](#verify)
    - [AOJ ITP1_7_D](#AOJ_ITP1_7_D)
    - [ABC009_D](#ABC009_D)
    - [yukicoder No.194](#yuki_194)
- [参考](#参考)

# アルゴリズム
特になし

# 実装例
- Matrix$(h,w)$ := $h$ 行 $w$ 列の行列を作成し，$0$ で初期化．
- Matrix$(G)$ := 行列を2次元配列 $G$ で初期化．
- height$()$, width$()$ := 行列のサイズを取得．
    - $O(1)$
- I$(n,x)$ := 単位元を $x$ とする $n$ 次単位行列．
    - $O(n^2)$
    - 零元も設定できるようにするべき？
- 演算子オーバーロード
    - 加法`+,+=`，差`-,-=` $O(n^2)$
    - 乗法`*,*=` $O(n^3)$
    - 添字アクセス`[]` $O(1)$
- pow$(k)$ := 行列累乗
    - $O(n^3\log k)$
    - 別でpower作って任意のクラスを載せられるほうがよくないか．取ってくるの面倒だけど
- 必要になったら作るやつ
    - 線形代数の勉強から始めないといけない
    - スカラー倍
    - 転置
    - 行列式
    - ランク
    - トレース

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Matrix/Matrix.cpp" >}}

# verify
<h4 id="AOJ_ITP1_7_D"><a href="https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_D">行列の積 - ITP1_7_D &mdash; AIZU ONLINE JUDGE</a></h4>

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Matrix/verify/ITP1_7_D.cpp" >}}

<h4 id="ABC009_D"><a href="https://atcoder.jp/contests/abc009/tasks/abc009_4">D - 漸化式 - AtCoder Beginner Contest 009 &mdash; AtCoder</a></h4>

$$
\begin{aligned}
    \left(
        \begin{array}{ccc}
            A _ {N+K} \\\ A _ {N+K-1} \\\ A _ {N+K-2} \\\ \vdots \\\ A _ {N+1}
        \end{array}
    \right)
    =
    \left(
        \begin{array}{ccc}
            C _ 1 & C _ 2 & \ldots & C _ {K-1} & C _ K \\\ 1 & 0 & \ldots & 0 & 0 \\\ 0 & 1 & \ldots & 0 & 0 \\\ \vdots & \vdots & \ddots & \vdots & \vdots \\\ 0 & 0 & \ldots & 1 & 0
        \end{array}
    \right)
    \left(
        \begin{array}{ccc}
            A _ {N+K-1} \\\ A _ {N+K-2} \\\ A _ {N+K-3} \\\ \vdots \\\ A _ {N}
        \end{array}
    \right)
\end{aligned}
$$

$$
\therefore
\begin{aligned}
    \left(
        \begin{array}{ccc}
            A _ {N+K} \\\ A _ {N+K-1} \\\ A _ {N+K-2} \\\ \vdots \\\ A _ {N+1}
        \end{array}
    \right)
    =
    \left(
        \begin{array}{ccc}
            C _ 1 & C _ 2 & \ldots & C _ {K-1} & C _ K \\\ 1 & 0 & \ldots & 0 & 0 \\\ 0 & 1 &  \ldots & 0 & 0 \\\ \vdots & \vdots & \ddots & \vdots & \vdots \\\ 0 & 0 & \ldots & 1 & 0
        \end{array}
    \right) ^ N
    \left(
        \begin{array}{ccc}
            A _ {K} \\\ A _ {K-1} \\\ A _ {K-2} \\\ \vdots \\\ A _ {1}
        \end{array}
    \right)
\end{aligned}
$$

AND演算の単位元が`UINT_MAX`であることに注意．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Matrix/verify/ABC009_D.cpp" >}}

<h4 id="yuki_194"><a href="https://yukicoder.me/problems/no/194">No.194 フィボナッチ数列の理解(1) &mdash; yukicoder</a></h4>

$$
\begin{cases}
    F(k) = S(k-1) - S(k-n-1) \\\ S(k) = F(k) + S(k-1)
\end{cases}
$$

$$
\therefore S(k) = 2S(k-1) - S(k-n-1)
$$

$$
\left(
    \begin{array}{ccc}
        S(k) \\\ S(k-1) \\\ \vdots \\\ S(k-n)
    \end{array}
\right) =
\left(
    \begin{array}{ccc}
        2 & 0 & \ldots & 0 & -1 \\\ 1 & 0 & \ldots & 0 & 0 \\\ 0 & 1 & \ldots & 0 & 0 \\\ \vdots & \vdots & \ddots & \vdots & \vdots \\\ 0 & 0 & \ldots & 1 & 0
    \end{array}
\right)
\left(
    \begin{array}{ccc}
        S(k-1) \\\ S(k-2) \\\ \vdots \\\ S(k-n-1)
    \end{array}
\right)
$$

$$
\therefore
\left(
    \begin{array}{ccc}
        S(k) \\\ S(k-1) \\\ \vdots \\\ S(k-n)
    \end{array}
\right) =
\left(
    \begin{array}{ccc}
        2 & 0 & \ldots & 0 & -1 \\\ 1 & 0 & \ldots & 0 & 0 \\\ 0 & 1 & \ldots & 0 & 0 \\\ \vdots & \vdots & \ddots & \vdots & \vdots \\\ 0 & 0 & \ldots & 1 & 0
    \end{array}
\right) ^ {k-n}
\left(
    \begin{array}{ccc}
        S(n) \\\ S(n-1) \\\ \vdots \\\ S(0)
    \end{array}
\right)
$$

要: [ModInt](../mod_int/)

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Matrix/verify/yuki194.cpp" >}}

# 参考
- [行列演算(Matrix) &mdash; Luzhiled's memo](https://ei1333.github.io/luzhiled/snippets/math/matrix.html)
- [行列ライブラリ &mdash; Learning Algorithms](http://www.learning-algorithms.com/entry/2017/10/13/193130)
- [ABC009 D - 漸化式 &mdash; ツバサの備忘録](https://emtubasa.hateblo.jp/entry/2018/09/07/131441)
