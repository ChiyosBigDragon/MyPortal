#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int t,w; cin>>t>>w;
    while(t--){
        long long ans[6];
        long long eq1[]={0,0,0,1ll<<50,1ll<<40,1ll<<33};
        long long eq2[]={1ll<<56,1ll<<28,1ll<<18,1ll<<14,1ll<<11,1ll<<9};
        long long ret;
        cout<<200<<endl;
        cout.flush();
        cin>>ret;
        ans[5]=(ret%eq1[4])/eq1[5];
        ans[4]=(ret%eq1[3]-ans[5]*eq1[5])/eq1[4];
        ans[3]=(ret-ans[4]*eq1[4]-ans[5]*eq1[5])/eq1[3];
        cout<<56<<endl;
        cout.flush();
        cin>>ret;
        ans[2]=(ret%eq2[1]-ans[3]*eq2[3]-ans[4]*eq2[4]-ans[5]*eq2[5])/eq2[2];
        ans[1]=(ret%eq2[0]-ans[2]*eq2[2]-ans[3]*eq2[3]-ans[4]*eq2[4]-ans[5]*eq2[5])/eq2[1];
        ans[0]=(ret-ans[1]*eq2[1]-ans[2]*eq2[2]-ans[3]*eq2[3]-ans[4]*eq2[4]-ans[5]*eq2[5])/eq2[0];
        for(int i=0;i<6;i++){
            cout<<ans[i]<<(i==5?"\n":" ");
        }
        int verdict; cin>>verdict;
        assert(verdict==1);
    }
    return 0;
}
