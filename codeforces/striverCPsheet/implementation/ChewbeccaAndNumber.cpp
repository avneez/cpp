#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define pbb pop_back
typedef long long ll;
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()

int main() {
    ll n; int mini;
    cin>>n;
    vector<ll> v;
    while(n>9){
        ll rem = n%10;
        n/=10;
        mini=min(rem,9-rem);
        v.pb(mini);
    }

    if (n==9)
        v.push_back(n);
    else if(n!=9){
        mini=min(n,9-n);
        v.pb(mini);
    }

    for (ll i = v.size() - 1; i >= 0; --i) {
        cout<<v[i];
    }

    return 0;
}
