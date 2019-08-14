#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using int64=long long;
const int INF=1145141919,MOD=1e9+7;
const int64 LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int t; cin>>t;
    for(int q=1;q<=t;q++){
        int a; cin>>a;
        string c[a]; rep(i,a) cin>>c[i];
        int len[a]; rep(i,a) len[i]=c[i].size();
        bool win[a]; rep(i,a) win[i]=0;
        string ans;
        for(int turn=0;turn<10100;turn++){
            bool r=0,s=0,p=0;
            for(int id=0;id<a;id++){
                if(win[id]) continue;
                if(c[id][turn%len[id]]=='R') r=1;
                if(c[id][turn%len[id]]=='S') s=1;
                if(c[id][turn%len[id]]=='P') p=1;
            }
            if(r&&s&&p){
                ans="IMPOSSIBLE";
                break;
            }else{
                if(r&&s) ans+='R';
                else if(s&&p) ans+='S';
                else if(p&&r) ans+='P';
                else if(r){
                    ans+='P';
                    break;
                }else if(s){
                    ans+='R';
                    break;
                }else if(p){
                    ans+='S';
                    break;
                }
            }
            char now=ans.back();
            for(int id=0;id<a;id++){
                if(!win[id]){
                    if(c[id][turn%len[id]]=='R'&&now=='P'){
                        win[id]=1;
                    }
                    if(c[id][turn%len[id]]=='S'&&now=='R'){
                        win[id]=1;
                    }
                    if(c[id][turn%len[id]]=='P'&&now=='S'){
                        win[id]=1;
                    }
                }
            }
            if(turn==10099){
                ans="IMPOSSIBLE";
            }
        }
        printf("Case #%d: ",q);
        cout<<ans<<endl;
    }
    return 0;
}
