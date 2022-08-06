// #include<bits/stdc++.h>
// using namespace std;
// #define rep(i,a,b) for(int i=a; i<b; i++)
// #define pb push_back
// #define pbb pop_back
// typedef long long ll;
// #define pii pair<int,int>
// #define all(x) (x).begin(),(x).end()

// bool solvemax(string a, string b, int n, int m){
//     if(n==1){
//         if(a==b) return true;
//         else return false;
//     }
//     int maxi; bool flag; string temp;
//         rep(i,0,n-1){
//             maxi = max(a[0],a[1]);
//             a[1]=maxi;
//             a=a.substr(1,n);
//             if(a==b) return true;
//         }
//         return false;
// }

// bool solvemin(string a, string b, int n, int m){
//     if(n==1){
//         if(a==b) return true;
//         else return false;
//     }
//         int mini; bool flag;
//         rep(i,0,n-1){
//             mini = min(a[0],a[1]);
//             a[1]=mini;
//             a=a.substr(1,n);
//             if(a==b) return true;
//         }
//         return false;
// }

// int main(){
//    int t; cin>>t;
//    while(t--){
//     int n,m; string a,b;
//     cin>>n>>m;
//     cin>>a>>b;
//     // vector<int> v(n);
//     // rep(i,0,n){
//     //     v[i]=a[i]-'0';
//     // }

//     if(solvemax(a,b,n,m) or solvemin(a,b,n,m))
//         cout<<"YES";
//     else cout<<"NO";
//     cout<<endl;
//    }
// return 0;
// }

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld=long double;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    t=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        ll last=s2.size()-1,x=-1;
        for (ll i = s1.size()-1; i >= 0; i--){
            if (last<0){
                break;
            }
            if (s1[i]==s2[last]){
                last--;
            }
            else{
                x=i;
                break;
            }
        }
        if (last<0){
            cout<<"YES\n";
        }
        else if (last>0){
            cout<<"NO\n";
        }
        else{
            ll c=0;
            for (ll i = 0; i < x; i++){
                if (s1[i]==s2[0]){
                    c++;
                    break;
                }
            }
            if (c>0){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
}