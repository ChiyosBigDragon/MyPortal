<<<<<<< HEAD
---
title: "ModInt"
draft: false
---

# 概略
全自動mod取り機

# 目次
- [アルゴリズム](#アルゴリズム)
- [実装例](#実装例)
- [verify](#verify)
    - [Chokudai Speed Run 001_G](#ch_G)
    - [yukicoder No.194](#yuki_194)
- [参考](#参考)

# アルゴリズム
逆元の実装について補足．

$a^{-1} \mod b$ を求めるには
$$ax + by = 1$$
を満たす $x$ を求めることが必要である．ここで
$$
\left(
    \begin{array}{ccc}
        a & 1 & 0 \\\ b & 0 & 1
    \end{array}
\right)
\left(
    \begin{array}{ccc}
        -1 \\\ a \\\ b
    \end{array}
\right)
= {\bm 0}
$$
という自明な式を考える．この式は行基本変形を用いて，次の形に持っていくことが出来る．
$$
\left(
    \begin{array}{ccc}
        \gcd(a,b) & x & y \\\ 0 & u & v
    \end{array}
\right)
\left(
    \begin{array}{ccc}
        -1 \\\ a \\\ b
    \end{array}
\right)
= {\bm 0}
$$
1行目に注目すると
$$ax + by = \gcd(a,b) = 1$$
であるから，行基本変形の間に $ax + by = 1$ を満たす $x$ が求まっている事がわかる．

したがってライブラリ内で行うことは
$$
\left(
    \begin{array}{ccc}
        a & s & - \\\ b & t & -
    \end{array}
\right)
$$
を初期値 $(a,b,s,t) = (a,b,1,0)$ として，行基本変形を $b = 0$ になるまで繰り返すだけである．

# 実装例
- ModInt<$p$>$(x)$ := $\mod p$ の演算をサポート
- 演算子オーバーロード
    - 負号`-`
    - 加法`+``+=`
    - 減法`-``-=`
    - 乗法`*``*=`
    - 除法`/``/=`
    - 等号`==``!=`
    - 入出力`>>``<<`
- pow$(n)$ := $x^n \mod p$
    - $O(\log n)$
- inverse$()$ := $x$ の逆元を返す
    - $x$ と$p$ がフィボナッチ数列の隣接2項であるとき，最悪計算量$O(\log_{\gamma} p)(\gamma = \frac{1+\sqrt{5}}{2})$

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/ModInt/ModInt.cpp" >}}

# verify
<h4 id="ch_G"><a href="https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_g">G - あまり - Chokudai SpeedRun 001 &mdash; AtCoder</a></h4>

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/ModInt/verify/ChokudaiSpeedRun001_G.cpp" >}}

<h4 id="yuki_194"><a href="https://yukicoder.me/problems/no/194">No.194 フィボナッチ数列の理解(1) &mdash; yukicoder</a></h4>

要: [Matrix](../matrix/)

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Matrix/verify/yuki194.cpp" >}}

# 参考
- [Euclidean algorithm (Blankinship algorithm) &mdash; 週刊 spaghetti_source](https://topcoder.g.hatena.ne.jp/spaghetti_source/20130126/1359171466)
- [modint 構造体を使ってみませんか？ (C++) &mdash; noshi91のメモ](http://noshi91.hatenablog.com/entry/2019/03/31/174006)
- [Mod-Int &mdash; Luzhiled's memo](https://ei1333.github.io/luzhiled/snippets/math/mod-int.html)

### 入出力にfriendを付ける意味？
[第４３章　心の友よ！ &mdash; ロベールの部屋](http://www7b.biglobe.ne.jp/~robe/cpphtml/html02/cpp02043.html)

`cin>>int>>mod`や`cout<<mod`は左項が`ModInt`ではないのでクラス外から呼び出す必要がある．しかしそれだと`private`である`ModInt.x`にアクセスできないので`friend`で解決する？
=======
---
title: "ModInt"
draft: false
---

# 概略
全自動mod取り機

# 目次
- [アルゴリズム](#アルゴリズム)
- [実装例](#実装例)
- [verify](#verify)
    - [Chokudai Speed Run 001_G](#ch_G)
    - [yukicoder No.194](#yuki_194)
- [参考](#参考)

# アルゴリズム
逆元の実装について補足．

$a^{-1} \mod b$ を求めるには
$$ax + by = 1$$
を満たす $x$ を求めることが必要である．ここで
$$
\left(
    \begin{array}{ccc}
        a & 1 & 0 \\\ b & 0 & 1
    \end{array}
\right)
\left(
    \begin{array}{ccc}
        -1 \\\ a \\\ b
    \end{array}
\right)
= {\bm 0}
$$
という自明な式を考える．この式は行基本変形を用いて，次の形に持っていくことが出来る．
$$
\left(
    \begin{array}{ccc}
        \gcd(a,b) & x & y \\\ 0 & u & v
    \end{array}
\right)
\left(
    \begin{array}{ccc}
        -1 \\\ a \\\ b
    \end{array}
\right)
= {\bm 0}
$$
1行目に注目すると
$$ax + by = \gcd(a,b) = 1$$
であるから，行基本変形の間に $ax + by = 1$ を満たす $x$ が求まっている事がわかる．

したがってライブラリ内で行うことは
$$
\left(
    \begin{array}{ccc}
        a & s & - \\\ b & t & -
    \end{array}
\right)
$$
を初期値 $(a,b,s,t) = (a,b,1,0)$ として，行基本変形を $b = 0$ になるまで繰り返すだけである．

# 実装例
- ModInt<$p$>$(x)$ := $\mod p$ の演算をサポート
- 演算子オーバーロード
    - 負号`-`
    - 加法`+``+=`
    - 減法`-``-=`
    - 乗法`*``*=`
    - 除法`/``/=`
    - 等号`==``!=`
    - 入出力`>>``<<`
- pow$(n)$ := $x^n \mod p$
    - $O(\log n)$
- inverse$()$ := $x$ の逆元を返す
    - $x$ と$p$ がフィボナッチ数列の隣接2項であるとき，最悪計算量$O(\log_{\gamma} p)(\gamma = \frac{1+\sqrt{5}}{2})$

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/ModInt/ModInt.cpp" >}}

# verify
<h4 id="ch_G"><a href="https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_g">G - あまり - Chokudai SpeedRun 001 &mdash; AtCoder</a></h4>

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/ModInt/verify/ChokudaiSpeedRun001_G.cpp" >}}

<h4 id="yuki_194"><a href="https://yukicoder.me/problems/no/194">No.194 フィボナッチ数列の理解(1) &mdash; yukicoder</a></h4>

要: [Matrix](../matrix/)

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/Math/Matrix/verify/yuki194.cpp" >}}

# 参考
- [Euclidean algorithm (Blankinship algorithm) &mdash; 週刊 spaghetti_source](https://topcoder.g.hatena.ne.jp/spaghetti_source/20130126/1359171466)
- [modint 構造体を使ってみませんか？ (C++) &mdash; noshi91のメモ](http://noshi91.hatenablog.com/entry/2019/03/31/174006)
- [Mod-Int &mdash; Luzhiled's memo](https://ei1333.github.io/luzhiled/snippets/math/mod-int.html)

### 入出力にfriendを付ける意味？
[第４３章　心の友よ！ &mdash; ロベールの部屋](http://www7b.biglobe.ne.jp/~robe/cpphtml/html02/cpp02043.html)

`cin>>int>>mod`や`cout<<mod`は左項が`ModInt`ではないのでクラス外から呼び出す必要がある．しかしそれだと`private`である`ModInt.x`にアクセスできないので`friend`で解決する？
>>>>>>> 54248eef8b475d8bd295432f95cd5e31992bb1d4
