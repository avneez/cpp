//CodeChef ques - Snake and Transition from Capitalism to Socialism

#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define pbb pop_back
typedef long long ll;
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
const int N=1e3+10;
const int INF = 1e9+10;

int val[N][N];
int vis[N][N];
int lev[N][N];  //distance
int n,m;

vector<pii> dir = {{0,1},{1,0},{0,-1},{-1,0},{1,-1},{-1,1},{1,1},{-1,-1}};

bool isValid(int i, int j){
    return i>=0 and j>=0 and i<n and j<n;
}

int bfs(){
    int mx=INT_MIN;
    for (int i = 0; i <n; i++){
        for(int j=0; j<m; j++){
           mx=max(mx, val[i][j]);
        }
    }
    queue<pii> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mx==val[i][j]){
                q.push({i,j});
                lev[i][j]=0;
                vis[i][j]=1;
            }
        }
    }
    int ans = 0;
    while(!q.empty()){
        auto v=q.front();
        int vx = v.first;
        int vy = v.second;
        q.pop();
        for(auto d:dir){
            int childx = d.first + vx;
            int childy = d.second + vy;
            if(!isValid(childx,childy)) continue;
            if(vis[childx][childy]) continue;

            q.push({childx,childy});
            lev[childx][childy]=lev[vx][vy]+1;
            vis[childx][childy] = 1;
            ans = max(ans, lev[childx][childy]);
        }
    }
    return ans;
}

void reset(){
    for (int i = 0; i <n; i++){
        for(int j=0; j<m; j++){
            vis[i][j]=0;
            lev[i][j]=INF;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        reset();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>val[i][j];
            }
        }
        cout<<bfs()<<endl;
    }

return 0;
}