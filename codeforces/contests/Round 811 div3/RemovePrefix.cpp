#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int>& v, int n){
//     int c=0;
//     for(int i=1; i<n; i++){
//         for(int j=i-1; j<n-1; j++){
//             if(v[i]==v[j]) c++;
//         }
//     }
//     return c;
// }

int main(){
    int t; cin>> t; int c=0;
    while(t--){
        // set<int> s;
        int n;
        cin>>n;
        int v[n];
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        unordered_map<int,int>mp;
        int c=0;
        for(int i=0;i<n;i++)
            mp[v[i]]++;
        cout<<c<<" ";
        for(int i=1;i<n;i++)
        {
            if(mp.find(v[i])!=mp.end())
            {

            if(mp[v[i]]>1)
                {
                  mp[v[i]]--;
                  c++;
                }
            }
        }
        // if(n==1) cout<<0;
        // for(auto it:v) s.insert(it);
        // cout<<n-s.size()<<endl;
    }
return 0;
}