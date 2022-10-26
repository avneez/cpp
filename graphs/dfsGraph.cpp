// Depth First Search (DFS) for Graph

// DFS-I: Given an undirected graph and a source vertex s, print DFS from the given source.**

// I/P: s=0,       0
//               /   \
//              1     4
//             /     / \
//            2     5---6

// O/P: 0, 1, 2, 4, 5, 6
// Algorithm:
// 1. Create a recursive function that takes the index of node and a visited array.
// 2. Mark the current node as visited and print the node.
// 3. Traverse all the adjacent and unmarked nodes and call the recursive function with index of adjacent node.
// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	void DFSUtil(int s, vector<int> adj[], bool visited[], vector<int> &res){
	    if(visited[s]) return;
	    visited[s] = true;
	    res.push_back(s);
	    for (int u : adj[s]){
	        if (!visited[u])
	            DFSUtil(u, adj, visited, res);
	    }
	}

	vector<int> dfsOfGraph(int V, vector<int> adj[]){
	    bool visited[V];
	    memset(visited, false, sizeof(visited));

	    vector <int> res;
	    for (int i = 0; i < V; i++)
	        if (!visited[i]){
	            DFSUtil (i, adj, visited, res);
	        }
	    return res;
	}
};

// DFS-II: DFS on disconnected graphs (No Source Given).

// I/P: No source given         0              4
//                  	      /    \         /   \
//                           1      2       5-----3
//                            \    /
//                               6

// O/P: 0, 1, 6, 2, 3, 4, 5
// Time Complexity: O(V + E)
// Space Complexity: O(V)

void DFSRec(vector<int> adj[], int s, bool visited[]) {
    visited[s]=true;
    cout<< s <<" ";

    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

void DFS(vector<int> adj[], int V){
    bool visited[V];
	for(int i = 0;i<V; i++)
		visited[i] = false;

    for(int i=0;i<V;i++){
        if(visited[i]==false)
            DFSRec(adj,i,visited);
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


// Output: Following is Depth First Traversal for disconnected graphs: 0 1 6 2 3 4 5
// DFS-III: Number of Islands in a graph (or number of connected components in a graph).

// I/P:             0              4
//        	       /    \         /   \
//               7----- 8      1      2       5-----3
//                              \    /
//                                 6

// O/P: 3 (connected components)
// Time Complexity: O(V + E)
// Space Complexity: O(V)

void DFSRec(vector<int> adj[], int s, bool visited[]) {
    visited[s]=true;
    for(int u:adj[s]){
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}

int DFS2(vector<int> adj[], int V){
    int count=0;
    bool visited[V];
	for(int i = 0;i<V; i++)
		visited[i] = false;

    for(int i=0;i<V;i++){
        if(visited[i]==false)
            {DFSRec(adj,i,visited);count++;}
    }
    return count;
}


int main() {
	int V=7;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,2,3);
	addEdge(adj,1,3);
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);

	cout << "Following is Depth First Traversal for disconnected graphs: "<< endl;
	DFS(adj,V);

	return 0;
}


// Application of DFS

// Cycle Detection
// Topological Sorting
// Strongly Connected Components
// Path Finding
// Solving Maze and Similar Puzzles