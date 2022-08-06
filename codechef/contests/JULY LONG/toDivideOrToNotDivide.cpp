#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        if(a%b==0){
            cout<<-1<<endl;
            continue;
        }
        ll ans=n;
        if(ans%a!=0) ans = n+a-(n%a);
        while(!(ans%a==0 and ans%b!=0)) ans+=a;
        cout<< ans <<endl;
    }
return 0;
}