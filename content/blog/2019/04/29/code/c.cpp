#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

template<class T>
struct SegmentTree{
    using F=function<T(T,T)>;
    const T init;
    const F f;
    int sz;
    vector<T> seg;
    SegmentTree(int n,const T init,const F f):
        init(init),
        f(f)
        {
            sz=1;
            while(sz<n) sz<<=1;
            seg.resize(sz<<1,init);
        }
    // 代入
    void set(int id,T x){
        seg[id+sz]=x;
    }
    // 構築
    void build(){
        for(int k=sz-1;k>0;k--){
            seg[k]=f(seg[2*k],seg[2*k+1]);
        }
    }
    // 更新
    void update(int id){
        while(id>>=1){
            seg[id]=f(seg[2*id],seg[2*id+1]);
        }
    }
    // 置換
    void replace(int id,T x){
        id+=sz;
        seg[id]=x;
        update(id);
    }
    // 加算
    void add(int id,T x){
        id+=sz;
        seg[id]+=x;
        update(id);
    }
    // [l,r)の結果を取得
    T get(int l,int r){
        T L=init,R=init;
        l+=sz,r+=sz;
        for(;l<r;l>>=1,r>>=1){
            if(l&1) L=f(L,seg[l++]);
            if(r&1) R=f(seg[--r],R);
        }
        return f(L,R);
    }
    // debug
    void debug(){
        int i=1;
        for(int r=2;r<=2*sz;r<<=1){
            while(i<r){
                cout<<seg[i++]<<" ";
            }
            cout<<"\n";
        }
    }
};

int main(){
    int t; cin>>t;
    for(int Q=1;Q<=t;Q++){
        int n,k; cin>>n>>k;
        SegmentTree<int> c(n,0,[](int a,int b){return max(a,b);});
        rep(i,n){
            int cc; cin>>cc;
            c.set(i,cc);
        }
        c.build();
        SegmentTree<int> d(n,0,[](int a,int b){return max(a,b);});
        rep(i,n){
            int dd; cin>>dd;
            d.set(i,dd);
        }
        d.build();
        int ans=0;
        for(int l=0;l<n;l++){
            for(int r=l+1;r<=n;r++){
                int cc=c.get(l,r);
                int dd=d.get(l,r);
                if(abs(cc-dd)<=k) ans++;
            }
        }
        printf("Case #%d: %d\n",Q,ans);
    }
    return 0;
}
