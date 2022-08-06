#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        long long n;
        cin>>a>>b>>n;
        int c=0;

        while(a<=n and b<=n){
            if(a<b){
                a+=b; c++;
            }
            else{
                b+=a; c++;
            }
        }
        cout<<c<<endl;
    }
return 0;
}