#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int dfs(vector<string> v){
    map<char,vector<string>> mp;
    int cnt=0;
    for(auto s:v){
        if(s!="") mp[s[0]].push_back(s.substr(1));
        else cnt++;
    }
    int ret=0;
    bool flg=0;
    for(auto x:mp){
        if((int)x.second.size()>1){
            ret+=dfs(x.second);
            flg=1;
        }else if((int)x.second.size()==1){
            flg=1;
        }
    }
    if(flg||cnt>0) ret+=2;
    return min(ret,(int)v.size()/2*2);
}

int main(){
    int t; cin>>t;
    for(int q=1;q<=t;q++){
        int n; cin>>n;
        string w[n]; rep(i,n) {
            cin>>w[i];
            reverse(all(w[i]));
        }
        map<char,vector<string>> mp;
        for(auto s:w){
            if(s!="") mp[s[0]].push_back(s.substr(1));
        }
        int ans=0;
        for(auto x:mp){
            if((int)x.second.size()>1){
                ans+=dfs(x.second);
            }
        }
        cout<<"Case #"<<q<<": "<<min(ans,n/2*2)<<endl;
    }
    return 0;
}
