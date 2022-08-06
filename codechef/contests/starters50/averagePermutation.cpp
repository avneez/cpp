#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
    int k; cin>>k;
        if(k==3){
            cout<<1<<" "<<2<<" "<<3<<endl;
            continue;
        }
        cout<<k<<" "<<k-2<<" ";
        for(int i=1; i<k-3; i++){
            cout<<i<<" ";
        }
        cout<<k-3<<" "<<k-1<<endl;
    }
return 0;
}