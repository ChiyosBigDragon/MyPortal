---
title: "構文解析で当分快適に"
date: 2019-05-10T06:00:00+09:00
draft: true
tags: ["Parse"]
topics: ["CompetitiveProgramming"]
---

~~ちょっとこのタイトル大数っぽくないですか？~~

今年もICPCの季節がやって来ましたね．弊学も競プロの課外活動が始まりました．今年は学内で20チームは出るんじゃないかという盛況ぶりです．新入生には強者も多く，内心焦っております．学内ボーダーはやめてね．

ICPCは3人1組のチーム戦なので，当然戦略が大事になってきます．色んな戦略があると思いますが，なんといっても大事なのは「〇〇のプロ」を確立することでしょう．「お茶汲みのプロ」も悪くはないですが，〇〇は出題分野がいいと思います．今回は〇〇に入る分野の一つ，「構文解析」をやっていきます．

## 構文解析の概要


## ICPCにおける構文解析

ICPCといえば構文解析，構文解析といえばICPC，ということでここ10年ほどの出題を見てみましょう．国内に限定しています．

- [2018-G][]
- [2017-E][]
- [2015-C(?)][2015-C]
- [2013-C][]
- [2012-F][]
- [2011-B(?)][2011-B]
- [2008-C][]

多い上にアジア進出の勘所だと言わんばかりの出題位置．

簡単な問題から．
-

## 構文解析全問レビュー
### [スマート計算機 &mdash; Aizu Online Judge][aoj0109]
BNFがありません．自分で作ります．難しいですが，演算子の優先順位や，等価な項を考えると見通しがよくなります．
```
<expr> ::= <term> | <expr>+<term> | <expr>-<term>
<term> ::= <fact> | <term>*<fact> | <term>/<fact>
<fact> ::= <numb> | (<expr>)
<numb> ::= [1-9] [0-9]*
```
適当に書くと上のような左再帰の形になってしまい，このまま実装すると間違いなく無限ループが発生します．左再帰は繰り返しに置き換えます．
```
<expr> ::= <term> [ +<term> | -<term> ]*
<term> ::= <fact> [ *<fact> | /<fact> ]*
<fact> ::= <numb> | (<expr>)
<numb> ::= [1-9] [0-9]*
```
あとはこれを実装するだけです．`=`は気にしなくてもいいでしょう．
コードaoj0109

### [有限体電卓 &mdash; Aizu Online Judge][aoj0264]
スマート計算機をMODでするだけ．入出力が特殊なので注意．
コードaoj0264

### [如何に汝を満足せしめむ？ いざ数え上げむ… &mdash; ICPC国内予選2008C][2008-C]
```
<formula> ::= 0 | 1 | 2 | P | Q | R |
              -<formula> |
              (<formula>*<formula>) | (<formula>*<formula>)
```
二項演算子が厄介ですが，それ以外は素直な出題です．これが解ければ構文解析の実装で今後困ることはないはず．
コードaoj1155

### [恒等式 &mdash; ICPC模擬国内予選2012C][jag2012-C]
`=`で切ってしまって2式を独立に構文解析するといいと思います．
```
<formula> ::= T | F |
              a | b | c | d | e | f | g | h | i | j | k |
              - <formula> |
              (<formula>*<formula>) | (<formula>+<formula>) | (<formula>-><formula>)
```
`A -> B`はド・モルガンの法則から`-A ∨ B`になることに注意．
コードaoj2401

### [知識の証明 &mdash; ICPC模擬国内予選2018C][jag2018-C]
```
<Hash> ::= <Letter> | [<Op><Hash><Hash>]
<Op> ::= + | * | ^
<Letter> ::= a | b | c | d
```
典型的な全探索です．`<Op><Hash><Hash>`のように二項演算子が前に来る場合は，`Op()`などを用意しないほうがいい気がします．
コードaoj2883

### [（未）論理式圧縮機 &mdash; ICPC国内予選2017E][2017-E]
```
<E> ::= 0 | 1 | a | b | c | d |
        -<E> |
        (<E>^<E>) | (<E>*<E>)
```
```
0 ::= (0 * <E>) | (<E> * 0)
<E> ::= (1 * <E>) | (<E> * 1)
<E> ::= (0 ^ <E>) | (<E> ^ 0)
-<E> ::= (1 ^ <E>) | (<E> ^ 1)
```

### [Molecular Formula &mdash; ICPCアジア地区予選2003E][asia2003-E]
そのままでも解けますが，何か中間に挟むと見通しがよくなります．`<fact>`は`<Molecule>`1つ分のイメージです．
```
// <Molecule> ::= <fact> [<fact>]*
// <fact> ::= <Atom> [<Number>]? | (<Molecule>) <Number>
// <Atom> ::= [A-Z] [a-z]?
// <Number> ::= [1-9] [0-9]?
```
`()`の中が繰り返しの形なので，ループに終了条件を書くといいでしょう．原子量が見つからないなど，途中で処理をやめたい場合は`throw`がいいと思います．（ここらへんは雰囲気で書いている）
コードaoj1244

### [数式探し &mdash; ICPC国内予選2018G][2018-G]
しゃくとり
でも1*1*…* 1がやばいのでそこはまとめる
あと
(1+2)* 3+3 で3になるのが4つなわけなくない？うそ．1+2と(1+2)は別物だったりして

[2018-G]: https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Prelim/1630
[2017-E]: https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Prelim/1620
[2015-C]: https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Prelim/1602
[2013-C]: https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Prelim/1188
[2012-F]: https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Prelim/1184
[2011-B]: https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Prelim/1173
[2008-C]: https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Prelim/1155
[aoj0109]: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0109
[asia2003-E]: https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Regional/1244
[jag2012-C]: https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Prelim/2401
[jag2018-C]: https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Prelim/2883
[aoj0264]: https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0264
