#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int degree[MAX];

vector<int> terrorist(int n, int m, vector<vector<int>>&v){
    for (int i = 1; i <=n; i++) {
		degree[v[i][0]]++;
		degree[v[i][1]]++;
	}
    vector<int> num(n);
    for(int i=1; i<=n; i++){
        num[i]=i;
    }
    vector<int> ans;
    for(int i=1; i<=n; i++){
        ans.push_back(degree[i]);
        degree[i]=-1;
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v;

    for(int i=0; i<m;i++){
        int x,y;
        cin>>x>>y;
        vector<int>v1;
        v1.push_back(x);
        v1.push_back(y);
        v.push_back(v1);
    }

    vector<int> ans = terrorist(n,m,v);
    for(int i=0; i<n; i++){
        cout<<ans[i]<<"\n";
    }

	return 0;
}
