#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using int64=long long;
const int INF=1145141919,MOD=1e9+7;
const int64 LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int t,f; cin>>t>>f;
    for(int q=1;q<=t;q++){
        bool ok[119]; rep(i,119) ok[i]=0;
        int maxi[]={24,6,2,1};
        string ans;
        char ans1;
        for(int d=0;d<4;d++){
            vector<vector<int>> cnt(5);
            for(int i=1;i<=595;i+=5){
                if(ok[i/5]) continue;
                cout<<i+d<<endl;
                cout.flush();
                char tmp; cin>>tmp;
                cnt[tmp-'A'].push_back(i/5);
            }
            for(int i=0;i<5;i++){
                // cout<<cnt[i].size()<<endl;
                if((int)cnt[i].size()==maxi[d]){
                    for(int j:cnt[i]){
                        ok[j]=1;
                    }
                    if(d==3) ans1=char('A'+i);
                }else if((int)cnt[i].size()!=0&&d<3){
                    ans+=char('A'+i);
                }
            }
        }
        bool last[5]; rep(i,5) last[i]=0;
        for(char c:ans){
            last[c-'A']=1;
        }
        for(int i=0;i<5;i++){
            if(!last[i]){
                if(ans1-'A'!=i) ans+=char('A'+i);
            }
        }
        ans+=ans1;
        // printf("Case #%d: ",q);
        cout<<ans<<endl;
        cout.flush();
        char verdict; cin>>verdict;
        assert(verdict=='Y');
    }
    return 0;
}
