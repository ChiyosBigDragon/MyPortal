#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int t; cin>>t;
    for(int Q=1;Q<=t;Q++){
        int p,q; cin>>p>>q;
        int xl[q+3]={},xr[q+3]={};
        int yd[q+3]={},yu[q+3]={};
        while(p--){
            int x,y; cin>>x>>y;
            char d; cin>>d;
            if(d=='N'){
                yu[y+2]++;
                yu[q+2]--;
            }
            if(d=='E'){
                xr[x+2]++;
                xr[q+2]--;
            }
            if(d=='S'){
                yd[y]++;
                yd[0]--;
            }
            if(d=='W'){
                xl[x]++;
                xl[0]--;
            }
        }
        for(int i=1;i<q+3;i++){
            yu[i]+=yu[i-1];
            xr[i]+=xr[i-1];
        }
        for(int i=q+1;i>=0;i--){
            yd[i]+=yd[i+1];
            xl[i]+=xl[i+1];
        }
        int Y,ysum=0;
        for(int y=q+1;y>=1;y--){
            if(ysum<=yu[y]+yd[y]){
                Y=y;
                ysum=yu[y]+yd[y];
            }
        }
        int X,xsum=0;
        for(int x=q+1;x>=1;x--){
            if(xsum<=xl[x]+xr[x]){
                X=x;
                xsum=xl[x]+xr[x];
            }
        }
        printf("Case #%d: %d %d\n",Q,X-1,Y-1);
    }
    return 0;
}
