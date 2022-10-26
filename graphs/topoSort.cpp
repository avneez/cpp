#include <bits/stdc++.h>
using namespace std;
// const bool vis[10000];
// const int n=100;

class Graph{
public:
    int n;
    vector<int>* adj;

    Graph(int n){
        this->n=n;
        adj= new vector<int>[n];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    // void printGraph(vector<int> adj[], int n){
    //     for(int i=0; i<n; i++){
    //         for(int x: adj[i]){
    //             cout<<x<<" ";
    //           }
    //         cout<<"\n";
    //     }
    // }

    void dfs(int u, bool vis[], stack<int>& st)
    {
        vis[u] = true;
        for (auto i:adj[u])
        {
            if (vis[i] == false)
            {
                dfs(i, vis, st);
            }
        }
        st.push(u);

    }

    vector<int> topoSort(){
        stack<int> st;
        bool vis[n];
        memset(vis, false, sizeof(vis));
        for (int i=0; i<n; i++){
            if (vis[i] == false){
                dfs(i, vis, st);
            }
        }
        vector<int> topo;
        while (!st.empty()){
            int x = st.top();
            topo.push_back(x);
            // cout<<x<<" ";
            st.pop();
        }
        return topo;
    }
};

int main()
{
    // int n = 5;
    // vector<int> adj[n];

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    // g.printGraph(adj,n);

    vector<int> ans;
    ans =g.topoSort();
    for (auto it : ans){
        cout << it << " ";
    }

    return 0;
}