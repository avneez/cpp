#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define pbb pop_back
typedef long long ll;
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()

void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll> v;
    rep(i,0,n){
        ll water;
        cin>>water;
        v.pb(water);
    }
    sort(all(v),greater<int>()); //sorted in dec order
    ll ans=0;
    rep(i,0,k+1){
        ans+=v[i];
    }
    cout<<ans<<endl;

}

int main(){
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}