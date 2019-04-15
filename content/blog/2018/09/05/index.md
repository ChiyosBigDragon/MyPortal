---
title: "SRM511 Div1Easy Zoo"
date: 2018-09-05T09:00:00+09:00
draft: false
tags: ["SRM","Ad hoc"]
topics: ["CompetitiveProgramming"]
---

これ本家のカテゴリが *Recursion* なんですけど，どうなんですかね．

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=11485

## 概略
ウサギとネコが合わせて $N$ 匹いる．彼らの身長は互いに異なる．

1匹ずつに次の質問をする．
「あなたと同じ種類で，あなたよりも身長が高い動物は何匹いるか？」

彼らの回答が全て正しいものとするとき，それを構成するウサギまたはネコの割り当ては何通りあるか．

### 補足
`{0,0,1,1,2}`という回答が得られたとき，ウサギを`R`，ネコを`C`とすると，

- `{R,C,R,C,R}`
- `{R,C,R,C,C}`
- `{R,C,C,R,R}`
- `{R,C,C,R,C}`
- `{C,R,R,C,R}`
- `{C,R,R,C,C}`
- `{C,R,C,R,R}`
- `{C,R,C,R,C}`

の8通りが考えられます．

## 方針
$2^{40}$ をシミュレートすることはまず無理．

とりあえず`answers`をソートしてみる．ウサちゃんもネコちゃんも同じ身長の同種はいないとのことなので，構築可能であるとき，

`answers={0,0,1,1,2,2,…,n-1,n-1,n,n+1,n+2,…,m}`

になる．逆にこうでないものは全て弾く必要があってこれが結構面倒．実装では`map`で数えて`unique`を取っている．

各数字へのウサギとネコの割り振り方は，

$$ 2(多いほうがウサギかネコの2通り) \times 2^{n} = 2^{n+1} $$

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/511Div1E_Zoo.cpp" >}}
