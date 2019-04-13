#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int r,c;
bool used[25][25];
vector<pair<int,int>> ans;
bool en=0;

bool ok(int y,int x,int ny,int nx){
    if(y==ny) return false;
    if(x==nx) return false;
    if(y-x==ny-nx) return false;
    if(y+x==ny+nx) return false;
    return true;
}

bool dfs(int y,int x,vector<pair<int,int>> v){
    if(en) return true;
    if((int)v.size()==r*c){
        if(!en){
            ans=v;
            en=1;
        }
        return true;
    }
    if(used[y][x]) return false;
    // cout<<y<<" "<<x<<endl;
    used[y][x]=true;
    bool ret=false;
    v.push_back({y,x});
    for(int ny=0;ny<r;ny++){
        for(int nx=0;nx<c;nx++){
            if(ok(y,x,ny,nx)){
                ret|=dfs(ny,nx,v);
            }
        }
    }
    used[y][x]=false;
    return ret;
}

int main(){
    int t; cin>>t;
    for(int q=1;q<=t;q++){
        cin>>r>>c;
        bool flg=0;
        en=0;
        for(int y=0;y<r;y++){
            for(int x=0;x<c;x++){
                rep(i,r)rep(j,c) used[i][j]=0;
                vector<pair<int,int>> v={};
                if(dfs(y,x,v)){
                    flg=1;
                    break;
                }
            }
            if(flg) break;
        }
        if(flg){
            cout<<"Case #"<<q<<": "<<"POSSIBLE"<<endl;
            for(auto x:ans){
                cout<<x.first+1<<" "<<x.second+1<<endl;
            }
        }else{
            cout<<"Case #"<<q<<": "<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
