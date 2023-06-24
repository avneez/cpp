#include<bits/stdc++.h>
using namespace std;


//1293. Shortest Path in a Grid with Obstacles Elimination

//You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle).
//You can move up, down, left, or right from and to an empty cell in one step.

//Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles.
//If it is not possible to find such walk return -1.

class Solution {
public:
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

    bool isvalid(int x,int y,vector<vector<int>> &grid){
        return (x>=0 && x<grid.size() && y>=0 && y<grid[0].size());
    }

    int solve(int x,int y,vector<vector<int>> &grid,int k,vector<vector<vector<int>>> &dp){
        if(x==grid.size()-1 && y==grid[x].size()-1) return 0;
        if(dp[x][y][k]!=-1) return dp[x][y][k];

        dp[x][y][k]=1e7;

        for(int i=0;i<4;i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(isvalid(nx,ny,grid)){
                if(grid[nx][ny]){
                    if(k>0)
                        dp[x][y][k]=min(dp[x][y][k],1+solve(nx,ny,grid,k-1,dp));
                }
                else
                    dp[x][y][k]=min(dp[x][y][k],1+solve(nx,ny,grid,k,dp));
            }
        }
        return dp[x][y][k];
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (k+1,-1)));
        int ans=solve(0,0,grid,k,dp);
        return ans>=1e7?-1:ans;
    }

    int shortestPathDijkstra(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<pair<int,pair<int,pair<int,int>>>,vector<pair<int,pair<int,pair<int,int>>>>,greater<pair<int,pair<int,pair<int,int>>>>>pq;
        vector<vector<int>>dis(m,vector<int>(n,-1));
        //{steps,k,x,y}
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        pq.push({0,{k,{0,0}}});
        dis[0][0]=k;
        while(!pq.empty()){
            int steps=pq.top().first;
            int obs=pq.top().second.first;
            int x=pq.top().second.second.first;
            int y=pq.top().second.second.second;
            pq.pop();
            if(x==m-1&&y==n-1){
                return steps;
            }
            for(int i=0;i<4;i++){
                int curr_x=x+dx[i];
                int curr_y=y+dy[i];
                if(curr_x>=0&&curr_x<m&&curr_y>=0&&curr_y<n){
                    int newObstacles=obs-grid[curr_x][curr_y];
                    if(newObstacles>=0&&newObstacles>dis[curr_x][curr_y]){
                        pq.push({steps+1,{newObstacles,{curr_x,curr_y}}});
                        dis[curr_x][curr_y]=newObstacles;
                    }
                }
            }

        }
        return -1;

    }

    int shortestPathBFS(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // This vector stores the number of obstacles that we can still remove after walking through that cell
        vector<vector<int>> visited(m, vector<int>(n, -1));

        queue<vector<int>> q;
        // x, y, currentLength, remaining k
        q.push({0,0,0,k});
        while(!q.empty()){
            auto t = q.front();
            q.pop();

            int x = t[0], y = t[1];

            // Invalid cases being dealt here since it's easier to write one condition instead of 4 while pushing.
            if(x<0 || x>=m || y<0 || y>=n) continue;

            // If you've reached the end, great, return the currentLength!
            if(x == m-1 && y == n-1)
                return t[2]; //currentLength of the path

            // If we hit an obstacle & we don't have any Ks remaining, continue
            // If we still have Ks to spend, we spend 1.
            if(grid[x][y] == 1){
                if(t[3] > 0)
                    t[3]--;
                else
                    continue;
            }

            // If this cell is already visited with a K value lesser than this one, we would want to save Ks for future use, so we continue
            // This is the most important condition and part of the solution!
            if(visited[x][y]!=-1 && visited[x][y] >= t[3]){
                continue;
            }

            // We store the currentRemaining K after spending K (if required) into the visited matrix.
            visited[x][y] = t[3];

            // Push the adjacent nodes in the queue.
            q.push({x+1, y, t[2]+1, t[3]});
            q.push({x-1, y, t[2]+1, t[3]});
            q.push({x, y+1, t[2]+1, t[3]});
            q.push({x, y-1, t[2]+1, t[3]});
        }

        return -1;
    }
};


int main(){
    Solution ob;
    //tc1
    vector<vector<int>> grid1 ={{0,0,0},
                                {1,1,0},
                                {0,0,0},
                                {0,1,1},
                                {0,0,0}};
    int k1 = 1;

    //tc2
    vector<vector<int>> grid2 = {{0,1,1},{1,1,1},{1,0,0}};
    int k2=1;

    cout<<ob.shortestPathBFS(grid1,k1)<<endl;
    cout<<ob.shortestPath(grid2,k2)<<endl;

return 0;
}