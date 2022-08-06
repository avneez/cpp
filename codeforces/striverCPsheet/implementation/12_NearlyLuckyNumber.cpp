#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;
    string s=to_string(n);
    ll c=0;
    for(ll i=0; i<s.size(); i++){
        if(s[i]=='4' or s[i]=='7') c++;
    }

    string t=to_string(c);
    for(ll i=0; i<t.size(); i++){
        if(t[i]=='4' or t[i]=='7') i++;
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
return 0;
}