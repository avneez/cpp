#include<bits/stdc++.h>
using namespace std;

// int main(){
// int n;
// cin>>n;
// int c=0;

// while(n>0){
//     int x;
//     if(n>=100) x=100;
//     else if(n>=20) x=20;
//     else if(n>=10) x=10;
//     else if(n>=5) x=5;
//     else if(n>=1) x=1;
//     n=n-x;
//     c++;
// }
// cout<<c;
// return 0;
// }

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        vector<int> v1(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
            if(v[i]&2) v1.push_back(v[i]);
        }
        for(int i=0; i<n; i++){
            if(!v[i]&2)
                v1.push_back(v[i]);
        }
        int c=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((__gcd(v[i],2*v[j])>1) or (__gcd(v[j],2*v[i])>1)) c++;
            }
        }
        cout<<c<<endl;
    }
return 0;
}