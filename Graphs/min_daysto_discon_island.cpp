#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/
//You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally connected group of 1's.
//The grid is said to be disconnected if there are at least two islands or no islands at all.
//Return the minimum number of days to disconnect the island.
//Basically we want disconnected islands(more than 1 island) or no island at all(0 islands).

class Solution {
public:

    void dfs(int node,unordered_map<int,vector<int>> &adj,vector<bool> &visited,vector<int> &dist,
    vector<int> &low,int parent,int &timer,int &ap){
        dist[node]=low[node]=timer++;
        visited[node]=true;
        int child = 0;
        for(auto nei : adj[node]){
            if(nei == parent){
                continue;
            }
            if(!visited[nei]){
                dfs(nei,adj,visited,dist,low,node,timer,ap);
                low[node]=min(low[node],low[nei]);
                if(parent!=-1 && low[nei]>=dist[node]){
                    ap++;
                }
                child++;
            }
            else{
                low[node]=min(low[node],dist[nei]);
            }
        }
        if(parent==-1 && child>1){ 
            ap++;
        }
    }

    int minDays(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> X = {1,-1,0,0};
        vector<int> Y = {0,0,1,-1};
        int components = 0;                                                  //to count number of islands/components
        int ones = 0;                                                        //to count number of 1's in the grid
        unordered_map<int,vector<int>> adj;                                 //building the adjacency list of the graph,for connected 1's/islands
        queue<pair<int,int>> q;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j] == 1){                                         //found a new island
                    components++;
                    q.push({i,j});
                    while(!q.empty()){                                       //bfs to traverse the entire island and build the graph
                        auto it = q.front();
                        int r = it.first;
                        int c = it.second;
                        grid[r][c]=2;                                        //marking visited,so thatit is not processed again/included in adj list
                        q.pop();
                        int u = r * col + c;
                        adj[u];
                        ones++;
                        for(int k=0;k<4;k++){
                            int nx = X[k]+r;
                            int ny = Y[k]+c;
                            if(nx<row && nx >=0 && ny<col && ny >=0){
                                if(grid[nx][ny] == 1){
                                    int v = nx*col + ny;
                                    q.push({nx,ny});
                                    adj[u].push_back(v);
                                    adj[v].push_back(u);
                                }
                            }
                        }
                    }
                    
                }
            }
        }
        if(components>1){                                                              //already disconnected
            return 0; 
        }
        if(ones == 1){                                                                 //only one land cell, removing it will make 0 islands
            return 1;
        }
        int ap = 0;                                                                    //to count articulation points , if there is any articulation point, then removing that point will disconnect the island,therefore ans=1
        int timer = 0;
        vector<bool> visited(row*col,false);
        vector<int> dist(row*col,-1);
        vector<int> low(row*col,-1);
        for(int c = 0;c<row*col;c++){
            if(adj.find(c)!=adj.end()){                                                 //start dfs from those nodes which are present in the adj list(i.e land cells) and get articulation points
                if(!visited[c]){
                    dfs(c,adj,visited,dist,low,-1,timer,ap);
                    
                }
            }
        }
        if(ap != 0){                                                                     //there is at least one articulation point, so ans=1 because removing that point will disconnect the island
            return 1;
        }
        return 2;                                                                         //no articulation point, then in any case  we need to remove at least 2 points to disconnect the island
    }
};


//simpler solution , remove each 1 and check if the graph is disconnected or not using dfs/bfs

class Solution {
public:
    int n, m;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {                             //standard dfs to mark all connected 1's , to count islands/components
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                !vis[nx][ny] && grid[nx][ny] == 1)
                dfs(nx, ny, grid, vis);
        }
    }

    int countIslands(vector<vector<int>>& grid) {                                                            //count number of islands/components using dfs
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {                                                         //found an unvisited land cell
                    count++;                                                                                 //increment island/component count
                    dfs(i, j, grid, vis);                                                                    //dfs to mark all connected land cells as visited
                }
            }
        }
        return count;                                                                                        //return total islands/components found
    }

    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Step 1: Already disconnected
        if (countIslands(grid) != 1) return 0;                                                               //if already disconnected , return 0

        // Step 2: Try removing one cell ,(this case is for if there is one island/component only) check if it gets disconnected
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;                                                                          //remove the land cell temporarily, and
                    if (countIslands(grid) != 1) return 1;                                                   //check if the grid is disconnected now, if yes return 1 ,(that means that cell was an articulation point  )
                    grid[i][j] = 1;                                                                          // restore
                }
            }
        }

        // Step 3: Need at least 2 removals
        return 2;
    }
};
