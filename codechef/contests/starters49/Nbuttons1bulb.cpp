#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n;
        string s,r;
        cin>>n>>s>>r;

        int c1=0; int c2=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1') c1++;
            if(r[i]=='1') c2++;
        }
        // cout<<c1<<" "<<c2;
        if(abs(c2-c1)%2!=0) cout<<0;
        else cout<<1;
        cout<<endl;
    }
return 0;
}