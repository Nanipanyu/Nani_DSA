#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/critical-connections-in-a-network/
//A critical connection is an edge that, if removed, will make some server unable to reach some other server.
//using Tarjan's Algorithm to find bridges in an undirected graph


class Solution {
public:

    void dfs(int node,unordered_map<int,vector<int>> &adj,int parent,
    vector<int> &dist,vector<int> &low,vector<bool> &visited,int &step,vector<vector<int>> &ans){
        visited[node]=true;
        dist[node]=low[node]=step++;                                                     //initially set their discovery and low to step and increase the step number.
        for(auto nei : adj[node]){                                         
            if(nei==parent){                                                             //node is backtraking( going back to its parent)so we ignore it.
                continue;
            }
            if(!visited[nei]){
                dfs(nei,adj,node,dist,low,visited,step,ans);                             
                low[node]=min(low[node],low[nei]);                                       //after traversing through all the neighbours, when going to parent node update the low of parent node, because one of their neighbour might have backedge(i.e other way to reach)which may lead to a lower discovery time.
                if(low[nei]>dist[node]){                                                 //if low[neighbour]>disc[node] ,means there is only on way to reach the neighbour, hence it is a bridge edge
                    vector<int> bridge;
                    bridge.push_back(node);
                    bridge.push_back(nei);
                    ans.push_back(bridge);
                }
            }
            else{
                low[node]=min(low[node],dist[nei]);                                       //backedge, present(i.e there is on more way to reach the node, then update the low of node)
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(n,-1);                                                      //to track the discovery time of node
        vector<int> low(n,-1);                                                       //to track the lowest discovery time to reach that node(there may be more than 1 way to reach there,from another shorter path)
        vector<bool> visited(n,false);
        int parent = -1;                                                             //parent because it is undirected graph, so while traversing we may go back to parent, we have to ignore that
        int time = 0;
        vector<vector<int>> ans;
        for(int j=0;j<adj.size();j++){
            if(!visited[j]){
                dfs(j,adj,parent,dist,low,visited,time,ans);                          //using dfs to find bridges
            }
        }
        return ans;
    }
};