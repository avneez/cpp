#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define pbb pop_back
typedef long long ll;
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()

int main(){
    int t; cin>>t;
    while(t--){
        int dp[2] = {-1,-1};
        string s; cin>>s;
        ll ans =0;
        for(int i=0; i<s.size(); i++){
            int c = s[i]-'0';
            if(s[i]=='0' or s[i]=='1'){
                dp[c^(i%2)]=i;
            }
            int mn=min(dp[0],dp[1]);
            ans+=i-mn;
        }
        cout<<ans<<endl;
    }
return 0;
}