#include<bits/stdc++.h>
using namespace std;

    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846


    const int M=1e9+7;
    long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }

    ll modPow(ll a, ll b){
        if(b==0)
            return 1LL;
        if(b==1)
            return a%M;
        ll res=1;
        while(b){
            if(b%2==1)
                res=mul(res,a);
            a=mul(a,a);
            b=b/2;
        }
        return res;
    }

void solve(){
        int n;
        cin>>n;
        for(int i=0; i<143; i++){
            int sw = i*7;
            for(int j=0; j<201; j++){
                int fw = j*5;
                // if((n-sw-fw)>=0 and (n-sw-fw)%3==0){
                //     cout<<(n-sw-fw)/3<<" "<<j<<" "<<i<<endl;
                //     return;
                // }
                for(int k=0; k<334; k++){
                    int tw= k*3;
                    if((n-sw-fw-tw)==0){
                        cout<<k<<" "<<j<<" "<<i<<endl;
                        return;
                    }
                }
            }
        }
        cout<<"-1"<<endl;
    }

    int main(){
        int t;
        cin>>t;
        for(int i=1;i<=t;i++){
        //    cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }

