int main(){
    int t; cin>>t;
    for(int q=1;q<=t;q++){
        string n; cin>>n;
        string a,b;
        bool flg=0;
        for(char c:n){
            if(c=='4'){
                a=a+'2';
                b=b+'2';
                flg=1;
            }else{
                a=a+c;
                if(flg){
                    b=b+'0';
                }
            }
        }
        cout<<"Case #"<<q<<": "<<a<<" "<<b<<endl;
    }
    return 0;
}
