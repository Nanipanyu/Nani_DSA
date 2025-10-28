#include <bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/making-a-large-island/description/

//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
// Return the size of the largest island in grid after applying this operation.
// An island is a 4-directionally connected group of 1s.

class disjointset{                                                  //DSU class
    public :
    vector<int> parent,size;
    
    disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findparent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }

    void unionbysize(int u,int v){
        u = findparent(u);
        v = findparent(v);
        if(u == v) return;
        if(size[u]>size[v]){
            parent[v]=u;
            size[u]+=size[v];
        }
        else{
            parent[u]=v;
            size[v]+=size[u];
        }
    }

};


// Apprach 1
class Solution {
public:

    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> X = {0,0,1,-1};
        vector<int> Y = {1,-1,0,0};
        disjointset ds(row*col+1);
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){                                                      //making union of all 1's , finding connected components of 1's
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nx=i+X[k], ny=j+Y[k];
                        if(nx>=0 && nx<row && ny>=0 && ny<col && grid[nx][ny]==1){
                            ds.unionbysize(i*col+j, nx*col+ny);
                        }
                    }
                }
            }
        }
        int maxi = 0;
        for(int i=0;i<row;i++){                                                     //finding size of largest component of 1's
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int root = ds.findparent(i*col+j);
                    maxi = max(maxi, ds.size[root]);
                }
            }
        }
         for(int i=0;i<row;i++){                                                     //checking for each 0 , if we flip it to 1 , if there becomes a connected component what will be the size of connected component formed
            for(int j = 0;j<col;j++){
                if(grid[i][j]==0){
                    unordered_set<int> st;                                           //to store unique parents of connected components of 1's adjacent to this 0, because one 0 can be connected to multiple 1's of same component
                    for(int k = 0;k<4;k++){
                        int nx = X[k]+i;
                        int ny = Y[k]+j;
                        if(nx>-1 && nx<row && ny>-1 && ny<col && grid[nx][ny]==1){
                            st.insert(ds.findparent(nx*col + ny));
                        }
                    }
                    int currsize = 1; // flipped 0
                    for(auto it : st){                                            //adding sizes of all unique connected components of 1's adjacent to this 0 
                        currsize += ds.size[it];
                    }
                    maxi = max(maxi, currsize);
                }
            }
        }
        return maxi;
    }
};



// Appraoch 2 :

class Solution {
public:

    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> X = {0,0,1,-1};
        vector<int> Y = {1,-1,0,0};
        disjointset ds(row*col+1);
        queue<pair<int,int>> q;
        int maxi = 0;
        for(int i=0;i<row;i++){                                                        //making union of all 1's , finding connected components of 1's , using BFS
            for(int j = 0;j<col;j++){
                if(grid[i][j]==1){                                                       //if we find a 1 , we will start a BFS from there, marking all connected 1's as visited by changing them to 2 and doing union of all connected 1's
                    q.push({i,j});
                    grid[i][j]=2;
                }
                int compsize = 1;
                while(!q.empty()){                                                      //BFS
                    auto front  = q.front();
                    q.pop();
                    int r = front.first;
                    int c = front.second;
                    for(int k = 0;k<4;k++){
                        int nx = X[k]+r;
                        int ny = Y[k]+c;
                        if(nx>-1 && nx<row && ny>-1 && ny<col && grid[nx][ny]== 1){
                            ds.unionbysize((r*col + c),(nx*col + ny));                       //union of current 1 with adjacent 1
                            grid[nx][ny]=2;
                            compsize++;
                            q.push({nx, ny});
                        }
                    }
                }
                maxi = max(maxi,compsize);                                                   //updating maxi with size of current component of 1's found by BFS, at last it will have size of largest component of 1's
            }
        }
         for(int i=0;i<row;i++){                                                              //checking for each 0 , if we flip it to 1 , if there becomes a connected component what will be the size of connected component formed  
            for(int j = 0;j<col;j++){
                if(grid[i][j]==0){
                    unordered_set<int> st;                                                    //to store unique parents of connected components of 1's adjacent to this 0, because one 0 can be connected to multiple 1's of same component
                    for(int k = 0;k<4;k++){
                        int nx = X[k]+i;
                        int ny = Y[k]+j;
                        if(nx>-1 && nx<row && ny>-1 && ny<col && grid[nx][ny]==2){
                            st.insert(ds.findparent(nx*col + ny));
                        }
                    }
                    int currsize = 1; // flipped 0
                    for(auto it : st){                                                          //adding sizes of all unique connected components of 1's adjacent to this 0
                        currsize += ds.size[it];  
                    }
                    maxi = max(maxi, currsize);
                }
            }
        }
        return maxi;
    }
};