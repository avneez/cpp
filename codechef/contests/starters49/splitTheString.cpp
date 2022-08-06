#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int badness, c1=0,c2=0;

        for(int i=0;i<n;i++){
            if(s[i]=='0') c1++;
            else c2++;
        }
        badness = abs(c1-c2);
        if(badness%k==0)
            cout<<badness/k<<endl;
        else
            cout<<(badness/k)+1<<endl;
    }
return 0;
}