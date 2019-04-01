---
title: "SRM505 Div1Easy RectangleArea"
date: 2018-08-10T22:00:00+09:00
draft: true
tags: ["SRM","Math","Recursion"]
topics: ["CompetitiveProgramming"]
---

## URL
http://community.topcoder.com/stat?c=problem_statement&pm=11400

## 概略
小長方形を組み合わせた長方形の盤面が与えられる．小長方形の各々について，面積がわかっていれば`Y`，そうでなければ`N`と表記される．質問をするたび，任意の`N`が1つ`Y`に変化する．最低で何回質問をすれば盤面全てを`Y`に変えられるか．

## 方針
図の赤枠のように長方形をとる．このとき，頂点と接する4つの小長方形に着目する．

下図より，このうち3つの面積がわかっている(`Y`)ならば，残り1つの面積もわかる．このような作業を繰り返すといずれ盤面の`Y`が増えなくなるため，小長方形の面積を質問する必要がある．

質問する小長方形はどれでもよさそうだが確証はない．

追記1: ケースが大きいとTLEするらしい．再帰部分が明らかに怪しいがいまいちわからない．改善中…

追記2: creepさんなどの記事を参考にして通しました．TLE解では再帰時に頂点を全探索していたので $O(W^2H^2)$ だったが，実際には`N`→`Y`としたところに関係する場所しか変わらないので，$O(WH)$ に減らせるはず．結果として全体では $O(W^3H^3)$ → $O(W^2H^2)$ に削減．

<iframe src="https://hatenablog-parts.com/embed?url=https%3A%2F%2Fcreep06.hatenablog.com%2Fentry%2F2018%2F07%2F21%2F060000" style="border: 0; width: 100%; height: 190px;" allowfullscreen scrolling="no" allow="autoplay; encrypted-media"></iframe>

## 改善後
{{< code language="cpp" src="https://raw.githubusercontent.com/ChiyosBigDragon/SRM/master/500-519/505Div1E_RectangleArea.cpp" >}}

## 改善前
```cpp
#include <bits/stdc++.h>
using namespace std;

class RectangleArea {
public:
    int h,w;
    int board[51][51];
    int ret=-1;

    void greed(){
        for(int y=0;y<h-1;y++){
            for(int x=0;x<w-1;x++){
                for(int dy=y;dy<h;dy++){
                    for(int dx=x;dx<w;dx++){
                        if(board[y][x]+board[y][dx]+board[dy][x]+board[dy][dx]==3){
                            board[y][x]=board[y][dx]=board[dy][x]=board[dy][dx]=1;
                            greed();
                        }
                    }
                }
            }
        }
    }

    int minimumQueries( vector <string> known ){
        h=known.size();
        w=known[0].size();
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                if(known[y][x]=='Y') board[y][x]=1;
                else board[y][x]=0;
            }
        }

        while(1){
            ret++;
            greed();
            bool end=true;
            for(int y=0;y<h;y++){
                for(int x=0;x<w;x++){
                    if(board[y][x]==0){
                        board[y][x]=1;
                        end=false;
                        break;
                    }
                }
                if(!end) break;
            }
            if(end) break;
        }
        return ret;
    }
};
```
