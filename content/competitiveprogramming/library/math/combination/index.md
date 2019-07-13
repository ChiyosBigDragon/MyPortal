<<<<<<< HEAD
---
title: "Combination"
draft: false
---

# 概略
Combinationに係る諸計算のライブラリ

# 目次
- [アルゴリズム](#アルゴリズム)
    - [逆元](#逆元)
    - [パスカルの三角形](#パスカルの三角形)
- [実装例](#実装例)
    - [逆元](#inverse)
    - [パスカルの三角形](#pascal)
- [verify](#verify)
    - [AOJ 1501](#AOJ 1501)
    - [yukicoder No.117](#yuki_117)
    - [ABC021_D](#ABC021_D)
- [参考](#参考)

# アルゴリズム

## 逆元
$$ {}_{n} \mathrm{C} _ {r} = \frac{n!}{r!(n-r)!} $$
なので分数のmodを求めたい気持ちになる．ここで逆元を使う．

整数 $a$ と 素数 $p$ について
$$ p = \left\lfloor \frac{p}{a} \right\rfloor \times a + p\%a $$
mod $p$ とすると
$$ 0 \equiv \left\lfloor \frac{p}{a} \right\rfloor \times a + p\%a $$
$$ p\%a \equiv - \left\lfloor \frac{p}{a} \right\rfloor \times a $$
$$ p\%a \times a^{-1} \equiv - \left\lfloor \frac{p}{a} \right\rfloor $$
$$ a^{-1} \equiv - \left\lfloor \frac{p}{a} \right\rfloor \times (p\%a)^{-1} $$

ここで $p\%a < a$ であるから，小さい方から漸化的に求められる．

なお，$0^{-1}$ の値は未定義なので，最終的な式において $p\%a \neq 0$ でなければならない．そのため $p$ は素数である．（正確には $p$ と $a$ が互いに素）

## パスカルの三角形

$$
\begin{cases}
{}_{n} \mathrm{C} _ {r} = {}_{n-1} \mathrm{C} _ {r-1} + {}_{n-1} \mathrm{C} _ {r} \\\ {}_{n} \mathrm{C} _ {0} = {}_{n} \mathrm{C} _ {n} = 1
\end{cases}
$$

より漸化的に求められる．

# 実装例

<h2 id="inverse">逆元</h2>

$n,r \leq 10^6 $ 程度を想定している．$p$ は素数．

- Combination$(p)$ := mod $p$ 下で階乗，逆元，逆元の階乗を求める．
    - $O(n)$
- C$(n,r)$, P$(n,r)$, H$(n,r)$ := $ {}_{n} \mathrm{C} _ {r} , {}_{n} \mathrm{P} _ {r} , {}_{n} \mathrm{H} _ {r} $
    - $O(1)$

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Combination/inverse/combination.cpp" >}}

<h2 id="pascal">パスカルの三角形</h2>

$n,r \leq 10^3 $ 程度を想定している．$p$ は素数でなくてもよい．

- CombinationOnPascal$(p)$ := mod $p$ 下で二項係数を計算する．
    - $O(nr)$
- C$(n,r)$, P$(n,r)$, H$(n,r)$ := $ {}_{n} \mathrm{C} _ {r} , {}_{n} \mathrm{P} _ {r} , {}_{n} \mathrm{H} _ {r} $
    - $O(1)$

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Combination/pascal/combination_pascal.cpp" >}}

# verify
<h4 id="AOJ 1501"><a href="https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1501">AOJ1501 Grid &mdash; AIZU ONLINE JUDGE</a></h4>
mod 1,000,000,007 だと思っていたら～、<br>
mod 100,000,007 でした～。<br>
チクショー！！

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Combination/pascal/verify/AOJ1501.cpp" >}}

<h4 id="yuki_117"><a href="https://yukicoder.me/problems/no/117">No.117 組み合わせの数 &mdash; yukicoder</a></h4>

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Combination/inverse/verify/yuki117.cpp" >}}

<h4 id="ABC021_D"><a href="https://atcoder.jp/contests/abc021/tasks/abc021_d">D - 多重ループ - AtCoder Beginner Contest 021 &mdash; AtCoder</a></h4>

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Combination/inverse/verify/ABC021_D.cpp" >}}

# 参考
- [パスカルの三角形 &mdash; Wikipedia](https://ja.wikipedia.org/wiki/%E3%83%91%E3%82%B9%E3%82%AB%E3%83%AB%E3%81%AE%E4%B8%89%E8%A7%92%E5%BD%A2)
- [1~nまでの逆元をO(n)で求める方法 &mdash; takapt0226's diary](http://takapt0226.hatenablog.com/entry/2013/03/15/213551)
- [よくやる二項係数 (nCk mod. p)、逆元 (a^-1 mod. p) の求め方 &mdash; けんちょんの競プロ精進記録](http://drken1215.hatenablog.com/entry/2018/06/08/210000)
- [nCr mod mの求め方 &mdash; uwicoder](https://www37.atwiki.jp/uwicoder/pages/2118.html)
- [コウメ太夫 (@dayukoume) &mdash; Twitter](https://twitter.com/dayukoume)
=======
---
title: "Combination"
draft: false
---

# 概略
Combinationに係る諸計算のライブラリ

# 目次
- [アルゴリズム](#アルゴリズム)
    - [逆元](#逆元)
    - [パスカルの三角形](#パスカルの三角形)
- [実装例](#実装例)
    - [逆元](#inverse)
    - [パスカルの三角形](#pascal)
- [verify](#verify)
    - [AOJ 1501](#AOJ 1501)
    - [yukicoder No.117](#yuki_117)
    - [ABC021_D](#ABC021_D)
- [参考](#参考)

# アルゴリズム

## 逆元
$$ {}_{n} \mathrm{C} _ {r} = \frac{n!}{r!(n-r)!} $$
なので分数のmodを求めたい気持ちになる．ここで逆元を使う．

整数 $a$ と 素数 $p$ について
$$ p = \left\lfloor \frac{p}{a} \right\rfloor \times a + p\%a $$
mod $p$ とすると
$$ 0 \equiv \left\lfloor \frac{p}{a} \right\rfloor \times a + p\%a $$
$$ p\%a \equiv - \left\lfloor \frac{p}{a} \right\rfloor \times a $$
$$ p\%a \times a^{-1} \equiv - \left\lfloor \frac{p}{a} \right\rfloor $$
$$ a^{-1} \equiv - \left\lfloor \frac{p}{a} \right\rfloor \times (p\%a)^{-1} $$

ここで $p\%a < a$ であるから，小さい方から漸化的に求められる．

なお，$0^{-1}$ の値は未定義なので，最終的な式において $p\%a \neq 0$ でなければならない．そのため $p$ は素数である．（正確には $p$ と $a$ が互いに素）

## パスカルの三角形

$$
\begin{cases}
{}_{n} \mathrm{C} _ {r} = {}_{n-1} \mathrm{C} _ {r-1} + {}_{n-1} \mathrm{C} _ {r} \\\ {}_{n} \mathrm{C} _ {0} = {}_{n} \mathrm{C} _ {n} = 1
\end{cases}
$$

より漸化的に求められる．

# 実装例

<h2 id="inverse">逆元</h2>

$n,r \leq 10^6 $ 程度を想定している．$p$ は素数．

- Combination$(p)$ := mod $p$ 下で階乗，逆元，逆元の階乗を求める．
    - $O(n)$
- C$(n,r)$, P$(n,r)$, H$(n,r)$ := $ {}_{n} \mathrm{C} _ {r} , {}_{n} \mathrm{P} _ {r} , {}_{n} \mathrm{H} _ {r} $
    - $O(1)$

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Combination/inverse/combination.cpp" >}}

<h2 id="pascal">パスカルの三角形</h2>

$n,r \leq 10^3 $ 程度を想定している．$p$ は素数でなくてもよい．

- CombinationOnPascal$(p)$ := mod $p$ 下で二項係数を計算する．
    - $O(nr)$
- C$(n,r)$, P$(n,r)$, H$(n,r)$ := $ {}_{n} \mathrm{C} _ {r} , {}_{n} \mathrm{P} _ {r} , {}_{n} \mathrm{H} _ {r} $
    - $O(1)$

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Combination/pascal/combination_pascal.cpp" >}}

# verify
<h4 id="AOJ 1501"><a href="https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1501">AOJ1501 Grid &mdash; AIZU ONLINE JUDGE</a></h4>
mod 1,000,000,007 だと思っていたら～、<br>
mod 100,000,007 でした～。<br>
チクショー！！

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Combination/pascal/verify/AOJ1501.cpp" >}}

<h4 id="yuki_117"><a href="https://yukicoder.me/problems/no/117">No.117 組み合わせの数 &mdash; yukicoder</a></h4>

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Combination/inverse/verify/yuki117.cpp" >}}

<h4 id="ABC021_D"><a href="https://atcoder.jp/contests/abc021/tasks/abc021_d">D - 多重ループ - AtCoder Beginner Contest 021 &mdash; AtCoder</a></h4>

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Combination/inverse/verify/ABC021_D.cpp" >}}

# 参考
- [パスカルの三角形 &mdash; Wikipedia](https://ja.wikipedia.org/wiki/%E3%83%91%E3%82%B9%E3%82%AB%E3%83%AB%E3%81%AE%E4%B8%89%E8%A7%92%E5%BD%A2)
- [1~nまでの逆元をO(n)で求める方法 &mdash; takapt0226's diary](http://takapt0226.hatenablog.com/entry/2013/03/15/213551)
- [よくやる二項係数 (nCk mod. p)、逆元 (a^-1 mod. p) の求め方 &mdash; けんちょんの競プロ精進記録](http://drken1215.hatenablog.com/entry/2018/06/08/210000)
- [nCr mod mの求め方 &mdash; uwicoder](https://www37.atwiki.jp/uwicoder/pages/2118.html)
- [コウメ太夫 (@dayukoume) &mdash; Twitter](https://twitter.com/dayukoume)
>>>>>>> 54248eef8b475d8bd295432f95cd5e31992bb1d4
