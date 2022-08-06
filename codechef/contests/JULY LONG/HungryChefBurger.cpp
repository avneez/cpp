#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    ll x,y,n,r;
	    cin>>x>>y>>n>>r;

        int nb=0; int pb=0;
        nb=r/x; pb=r/y;
        if(x>r){
            cout<<-1<<endl;
            continue;
        }

        if(pb>=n){
            cout<<0<<" "<<n<<endl;
        }
        else if(nb<n){
            cout<<-1<<endl;
        }
        else {
            int xpb = y*n;
            int bpd = abs(y-x);
            int tpd = abs(xpb-r);
            int tnb = tpd/bpd;
            if(tpd % bpd!=0) tnb++;
            cout<<tnb<<" "<<n-tnb<<endl;
        }
	}
	return 0;
}
// 4
// 2 10 4 12
// 4 0
// 4 8 10 50
// 8 2
// 99 100 5 10
// -1
// 9 10 10 200
// 0 10