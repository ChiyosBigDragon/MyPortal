int main(){
    int t; cin>>t;
    for(int q=1;q<=t;q++){
        int n; cin>>n;
        string p; cin>>p;
        char ans[2*n-2];
        if(p[0]!=p.back()){
            for(int i=0;i<n-1;i++){
                ans[i]=p.back();
            }
            for(int i=n-1;i<2*n-2;i++){
                ans[i]=p[0];
            }
        }else{
            int cnt=0;
            for(int i=0;i<2*n-2;i++){
                if(p[0]!=p[i]) cnt++;
                if(p[0]!=p[i]&&p[0]!=p[i+1]){
                    break;
                }
            }
            for(int i=0;i<cnt;i++){
                if(p[0]=='E') ans[i]='S';
                else ans[i]='E';
            }
            for(int i=0;i<n-1;i++){
                if(p[0]=='E') ans[i+cnt]='E';
                else ans[i+cnt]='S';
            }
            for(int i=n-1+cnt;i<2*n-2;i++){
                if(p[0]=='E') ans[i]='S';
                else ans[i]='E';
            }
        }
        cout<<"Case #"<<q<<": ";
        for(char c:ans) cout<<c;
        cout<<endl;
    }
    return 0;
}
