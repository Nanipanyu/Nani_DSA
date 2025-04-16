#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

void dfs(int node,int &step,unordered_map<int,vector<int>> &adj,vector<int> &low,
    vector<int> &disc,vector<bool> &visited,int &parent,vector<vector<int>> &result){
        
        visited[node]=true; //amrk it visited
        disc[node]=low[node]=step++; //initially set their low and discovery to step and increase the step number.
        for(auto neighbour:adj[node]){ //traverse dfs
            if(neighbour==parent){ //node is backtraking( going back to its parent)
                continue;
            }
            if(!visited[neighbour]){ //if not backtracking and not visited
                dfs(neighbour,step,adj,low,disc,visited,node,result); 
                low[node]=min(low[node],low[neighbour]); //after traversing through all the neighbours, when going to parent node update the low of parent node, because one of their neighbour might have backedge(i.e other way to reach)
                //check edge is bridge
                if(low[neighbour]>disc[node]){ //beacuse if low[neighbour]<disc[node] , that means there is one more  way to reach neighbour(edge is not bridge) ,but if low[neighbour]>disc[node] ,means there is only on way to reach the neighbour, hence it is a bridge edge
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(neighbour);
                    result.push_back(ans);
                }
            }
            else{
                //backedge, present(i.e there is on more way to reach the node, then update the low of node)
                low[node]=min(low[node],disc[neighbour]);
            }
        }
    
    }
    
    vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
        // Write your code here
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<e;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<int> low(v,-1); //to track the lowest step(i.e lowest step to reach there, there may be more than 1 way to reach there)(if there is 1 more way to reach there then it will be equal to the low of root node of other path)
        vector<int> disc(v,-1); //to track the step to reach the node
        vector<bool> visited(v,false);
        int parent=-1;
        vector<vector<int>> result;// storing the nodes with bridge edges
        int step=0;
        for(int i=0;i<v;i++){
            if(visited[i]==false){
                // using dfs
                dfs(i,step,adj,low,disc,visited,parent,result);
            }
        }
        return result;
    }
