#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int> mini(adj.size(),-1);
        vector<bool> visited(adj.size(),false);
        queue<int> q;
        q.push(src);
        int count = 1;
        mini[src]=0;
        visited[src]=true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto j : adj[front]){
                if(!visited[j]){
                    q.push(j);
                    mini[j]=mini[front]+1;
                    visited[j]=true;
                }
            }
        }
        return mini;
    }
};