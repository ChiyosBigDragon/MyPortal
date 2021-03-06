---
title: "SRM504 Div1Easy MathContest"
date: 2018-08-04T12:00:00+09:00
draft: false
tags: ["SRM","Simulation"]
topics: ["CompetitiveProgramming"]
---

## URL
http://community.topcoder.com/stat?c=problem_statement&pm=11233

## 概略
ボールが1列に並んでおり，先頭から順に取り出す．取り出したボールの色によって，列に以下の操作がなされる．

- `white`
    - 列を反転させる
- `black`
    - 色を反転させる

操作終了までに取り出した`black`の数を求める．

## 方針
愚直に再現すればよさそう．でも色反転の操作がダルそうだったので，状態を別で保持しxorを使うことで省略．初めは以下のコードをsubmitしたが，システスでTLE．よく考えれば $O(N^2)$ なので当然．

```cpp
#include <bits/stdc++.h>
using namespace std;

class MathContest {
public:
   int countBlack( string ballSequence, int repetitions ) {
       int n=ballSequence.size();
       vector<bool> balls;
       for(int i=0;i<repetitions;i++){
           for(int j=0;j<n;j++){
               if(ballSequence[j]=='B') balls.push_back(1);
               else balls.push_back(0);
           }
       }
       int black=0; bool rev=1;
       while(balls.size()){
           bool color=balls.front();
           balls.erase(balls.begin());
           if(color^rev){
               reverse(balls.begin(),balls.end());
           }else{
               rev=!rev;
               black++;
           }
       }
       return black;
   }
};
```

- 一番上を取り出すときの`erase`
- スタック反転時の`reverse`

この二つが $O(N)$ なので省略する必要があったが，ここで異常に悩む．`erase`の代替を`pop_back`で考えていたため，`reverse`と両立できなかったのが原因．結局，`reverse`は色反転と同じようにフラグ管理で，`erase`は`index`を操作することで解決．

{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/504Div1E_MathContest.cpp" >}}

計算量を落とす問題がどうも苦手…
