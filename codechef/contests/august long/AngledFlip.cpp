#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define pbb pop_back
typedef long long ll;
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> res(m,vector<int> (n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int> (m,0));
        vector<vector<int>> b(n,vector<int> (m,0));
        vector<vector<int>> c(n,vector<int> (m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>a[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>b[i][j];
            }
        }

        bool f=0;
        while(c!=b){
            c=transpose(a);
            if(c==b) f=1;
        }
        if(f==1) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
return 0;
}