#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define pbb pop_back
typedef long long ll;
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()

int main(){
    int n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    if(n==0) cout<<0;
    int dr=(k*l)/nl;
    int lem=c*d;
    int salt=p/np;
    int ans=min(dr,min(lem,salt))/n;
    cout<<ans;
return 0;
}