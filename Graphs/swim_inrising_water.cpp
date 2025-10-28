#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/swim-in-rising-water/

//You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
// It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.
// You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
// Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

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

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {                 
        set<pair<int,pair<int,int>>> st;                                          //min-heap to store {elevation,{i,j}}
        st.insert({grid[0][0],{0,0}});                                            //inserting the starting point
        int row = grid.size();
        int col = grid[0].size();
        vector<int> X = {0,0,1,-1};
        vector<int> Y = {1,-1,0,0};
        disjointset ds(row*col);
        bool go = true;
        int maxi = grid[0][0];                                                     //to store the maximum elevation encountered on the path from (0,0) to (n-1,n-1)                                           
        while(go && !st.empty()){
            auto front = *st.begin();
            int curr = front.first;                                                 //current elevation
            int i = front.second.first;                                             //current i
            int j = front.second.second;                                            //current j
            st.erase(st.begin());
            maxi = max(maxi,curr);                                                  //updating maximum elevation encountered so far
            for(int k=0;k<4;k++){                                                   //traversing all 4 directions, through its neighbours
                int nx = X[k]+i;
                int ny = Y[k]+j;
                if(nx>-1 && nx<row && ny>-1 && ny<col){
                    if(ds.findparent(nx*col + ny) != ds.findparent(i*col + j)){      //if neighbour and current node are not already connected
                        st.insert({grid[nx][ny],{nx,ny}});                           //insert the neighbour into set
                        if(grid[nx][ny]==grid[row-1][col-1]){                        //if we have reached the destination cell
                            maxi = max(maxi,grid[nx][ny]);                           //updating maximum elevation encountered so far
                            go = false;
                        }
                        ds.unionbysize(i*col + j,nx*col + ny);                        //union of current cell and neighbour cell, so that when we reach a neighour cell , we dont visit the current/parent cell again
                    }
                }
            }
        }
        return maxi;
    }
};