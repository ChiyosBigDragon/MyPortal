---
title: "SRM671 Div1Easy BearCries"
date: 2019-08-20T12:00:00+09:00
draft: false
tags: ["SRM", "DP"]
topics: ["CompetitiveProgramming"]
---

## URL
https://community.topcoder.com/stat?c=problem_statement&pm=14010

## 概略
泣き顔とは，2つのセミコロンでアンダースコア1つ以上を囲んだもののことを言う．正規表現では`;_+;`である．

与えられた`message`をいくつかの部分列に分ける分け方のうち，過不足なく泣き顔が作れる分け方は何通りあるか．

## 方針
`dp[i][a][b] := iまで見て使っていない";"がa個，";_+"がb個`とします．過不足なく使うことを考えると，解は`dp[|message|][0][0]`です．

[kmjpさんのブログ](http://kmjp.hatenablog.jp/entry/2015/10/15/0900)の言葉を借りて，`;_+;`は「閉じている」，`;_*`は「開いている」と表現すると次のような遷移が考えられます．

- セミコロンが来たとき
  - 新たに開く
    - `dp[i][a][b] += dp[i - 1][a - 1][b]`
  - 1つ閉じる
    - `dp[i][a][b] += dp[i - 1][a][b + 1] * (b + 1)`
- アンダースコアが来たとき
  - 開いている`;`のみの状態に追加する
    - `dp[i][a][b] += dp[i - 1][a + 1][b - 1] * (a + 1)`
  - 開いている`;_+`の状態に追加する
    - `dp[i][a][b] += dp[i - 1][a][b] * b`

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/660-679/671Div1E_BearCries.cpp" >}}

## 反省
最初，普通に数学をして壊滅した．DP解に目標を絞るも，`dp[i][a][b] := iまで見て使っていない';'がa個，'_'がb個`からなかなか進まなかった．`;`，`;_`のような区別の仕方は典型なので，気づけなかったのは反省．

### 参考
- [ABC104D - We Love ABC](https://atcoder.jp/contests/abc104/tasks/abc104_d)
