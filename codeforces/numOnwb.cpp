#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    // cout << 2 << endl;
    // if(n==2){
    //     cout<<1<<" "<<2;
    //     return;
    // }
    // cout<<n-2<<" "<<n<<endl;
    // cout<<n-1<<" "<<n-1<<endl;

    // for(int i=n-3; i>=1; i--)
    //     cout<<i+2<<" "<<i<<endl;

    vector<int> v;
    vector<int> ans;

    for (int i = 1; i<=n; i++) v.push_back(i);

    while (v.size() > 1){
        int k=size(v);
        int sum = v[k-1] + v[k-2];
        ans.push_back(v[k-1]);
        ans.push_back(v[k-2]);
        v.pop_back();
        v.pop_back();
        if (sum % 2 == 0)
            v.push_back(sum / 2);
        else
            v.push_back((sum / 2) + 1);
    }
    cout<<2<<endl;
    for(int i=0; i<ans.size(); i+=2){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}