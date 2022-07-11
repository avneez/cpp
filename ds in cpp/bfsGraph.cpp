// Breadth First Search (BFS) for Graph

// BFS-I: Given an undirected graph and a source vertex s, print BFS from the given source.**

// I/P: s=0,         1-----3
//                  /       \
//                 0---------5
//                  \       /
//                   2-----4

// O/P: 0, 1, 2, 5, 3, 4
// Algorithm:
// 1. Use a boolean list to mark all the vertices as not visited.
// 2. Initially mark first vertex as visited(true).
// 3. Create a queue for BFS and push first vertex in queue.
// 4. While queue is not empty:
//    I. Keep adding front element in output list and popping it from queue.
//    II. Traverse over all the connected components of front element.
//    III. If they aren't visited, mark them visited and add to queue.
// 5. Return the output list.
// // Time Complexity: O(V + E)
// // Space Complexity: O(V)

#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
  	vector<int> bfsOfGraph(int V, vector<int> adj[]){
	    vector<bool> visited(V, false);
	    int s = 0;
	    visited[s] = true; 
	    vector<int> res;
	    queue<int> q;
	    q.push(s);
	    while (!q.empty()) {
	        int u = q.front();
	        res.push_back(u);
	        q.pop();
	        for(int v : adj[t]){
	            if(!visited[v]){ 
	                visited[v] = true;
	                q.push(v);
	            }
            }
	    }
	    return res;
  	}
};
// BFS-II: BFS on disconnected graphs (No Source Given).

// I/P: No source given             0             4
//                  	      /    \         /   \
//                              1      2       5-----3
//                               \    /
//                                  6

// O/P: 0, 1, 2, 6, 4, 5, 3
// Time Complexity: O(V + E)
// Space Complexity: O(V)


void BFS(vector<int> adj[], int s, bool visited[]) { 	
    queue<int>  q;
	visited[s] = true; 
	q.push(s); 
	while(q.empty()==false) { 
		int u = q.front(); 
		q.pop();
		cout << u << " "; 
		 
		for(int v:adj[u])
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
	} 
}

void BFSDin(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i = 0; i<V; i++) 
		visited[i] = false;
		
    for(int i=0; i<V; i++){
        if(visited[i]==false)
            BFS(adj,i,visited);
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
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

	cout << "Following is Breadth First Traversal: "<< endl; 
	BFSDin(adj,V); 

	return 0; 
} 

// Output: Following is Breadth First Traversal: 0 1 2 3 4 5 6 
// BFS-III: Number of Islands in a graph (or number of connected components in a graph).

// I/P:              0            4
//        	       /   \        /   \
//                7-----8      1     2       5-----3
//                              \   /
//                                6

// O/P: 3 (connected components)
// Time Complexity: O(V + E)
// Space Complexity: O(V)

void BFS(vector<int> adj[], int s, bool visited[]) { 	
    queue<int>  q;
    visited[s] = true; 
    q.push(s); 
    while(q.empty()==false) { 
	    int u = q.front(); 
	    q.pop();  
		 
	    for(int v:adj[u])
		 if(visited[v]==false){
		     visited[v]=true;
		     q.push(v);
		 }
    } 
}

int BFSDin(vector<int> adj[], int V){
    bool visited[V]; int count=0;
	for(int i = 0;i<V; i++) 
		visited[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            {BFS(adj,i,visited);count++;}
    }

    return count;
}


// Application of BFS:

// Shortest Path in an unweighted graph
// Cycle Detection
// Crawlers in Search Engine
// Social Networking Search
// In Garbage Collection
// Broadcasting