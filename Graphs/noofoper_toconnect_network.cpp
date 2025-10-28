#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
//n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi.
//given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
//Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
//Input: n = 4, connections = [[0,1],[0,2],[1,2]]
//Output: 1
//Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

class Solution {
public:

    void dfs(int node,unordered_map<int,vector<int>> &adj,vector<bool> &mst){
        mst[node]=true;
        for(auto nei : adj[node]){
            if(!mst[nei]){
                dfs(nei,adj,mst);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;                                         //atleast n-1 edges are required to connect n nodes
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(0);
        vector<bool> mst(n,false);
        int components = 0;
        for(int i=0;i<n;i++){
            if(!mst[i]){
                dfs(i,adj,mst);
                components++;                                                            //counting number of components in the graph
            }
        }
        return components-1;                                                             //to connect c components we need at least c-1 edges
    }
};