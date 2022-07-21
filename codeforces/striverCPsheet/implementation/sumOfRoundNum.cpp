#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define pbb pop_back
typedef long long ll;
#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

void solve(int n){
    if(n<=9){
        cout<< 1 <<endl;
        cout<<n;
    }
    else{
    string s=to_string(n);
    int size=s.size();
    int arr[size], k=0;

        for(int i=size-1;i>=0;i--){
            arr[i] = n%10;
            n=n/10;
            if(arr[i]!=0){
                k++;
            }
        }
        cout<<k<<endl;

        for(int j=0;j<size;j++){
            int num = arr[j]*(pow(10,(size-j-1)));
            if(num!=0){
                cout<< num <<" ";
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        solve(n);
        cout<<endl;
    }
    return 0;
}
