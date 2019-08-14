---
title: "Parsing"
draft: true
---

# 概略
根付き木における2頂点の共通祖先のうち，最も深いものを示す．

# 目次
- [アルゴリズム](#アルゴリズム)
- [実装例](#実装例)
- [verify](#verify)
    - [AOJ GRL_5_C](#AOJ GRL_5_C)
    - [ABC014_D](#ABC014_D)
- [参考](#参考)

# アルゴリズム

# 実装例

- LCA$(V,root,edge)$ := 頂点数 $V$，根 $root$ の根付き木 $edge$ に対する，EulerTourとRMQの構成．
    - $O(V)$
- get$(u,v)$ := 頂点 $u$ と $v$ のLCAを求める．
    - $O(\log{V})$

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/Library/master/GraphTheory/LCA/LCA.cpp" >}}

# verify

# 参考
- [構文解析 Howto &mdash; GitHub Gist](https://gist.github.com/draftcode/1357281)
- [再帰下降型構文解析 ( LL(1) ) &mdash; Spaghetti Source](http://www.prefield.com/algorithm/string/parser.html)

[AOJ0109 スマート計算機](https://onlinejudge.u-aizu.ac.jp/problems/0109)

```
<数式> ::= <乗除> [ ("+" | "-") <乗除> ]*
<乗除> ::= <括弧> [ ("*" | "/") <括弧> ]*
<括弧> ::= <数> | "(" <数式> ")"
<数> ::= 数
```

```
<expr> ::= <term> [ ("+" | "-") <term> ]*
<term> ::= <fact> [ ("*" | "/") <fact> ]*
<fact> ::= <numb> | "(" <expr> ")"
<numb> ::= 数
```

[AOJ2401 Equation 恒等式](https://onlinejudge.u-aizu.ac.jp/problems/2401)

x | y | -x | (x*y) | (x+y) | (x->y)
:--:|:--:|:--:|:--:|:--:|:--:
T | T | F | T | T | T
T | F | F | F | T | F
F | T | T | F | T | T
F | F | T | F | F | T

```
<expr> ::= 'T' | 'F' |
'a' | 'b' | 'c' | 'd' | 'e' | 'f' |
'g' | 'h' | 'i' | 'j' | 'k' |
'-' <expr> |
'(' <expr> '*' <expr> ')' |
'(' <expr> '+' <expr> ')' |
'(' <expr> '->' <expr> ')'
```

[AOJ2883 Proof of Knowledge 知識の証明](https://onlinejudge.u-aizu.ac.jp/problems/2883)

```
<Hash> ::= <Letter> | '['<Op><Hash><Hash>']'
<Op> ::= '+' | '*' | '^'
<Letter> ::= 'a' | 'b' | 'c' | 'd'
```

[AOJ1244 Molecular Formula](https://onlinejudge.u-aizu.ac.jp/problems/1244)

```
<Molecule> ::= <Atom> [ <Number> ] | '(' <Molecule> ')' <Number> | [ <Molecule> ]*
<Atom> ::= <CapitalLetter> [ <SmallLetter> ]
<Number> ::= '2' | '3' | … | '99'
<CapitalLetter> ::= 'A' | 'B' | … | 'Z'
<SmallLetter> ::= 'a' | 'b' | … | 'z'
```

[B - 異世界数式](https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_b)

```
<Molecule> ::= <Atom> [ <Number> ] | '(' <Molecule> ')' <Number> | [ <Molecule> ]*
<Atom> ::= <CapitalLetter> [ <SmallLetter> ]
<Number> ::= '2' | '3' | … | '99'
<CapitalLetter> ::= 'A' | 'B' | … | 'Z'
<SmallLetter> ::= 'a' | 'b' | … | 'z'
```
