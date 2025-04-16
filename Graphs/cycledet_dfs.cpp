#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
// template <typename T> :to not declare the datatype
using namespace std;

bool iscycledfs(int node,int parent,unordered_map<int , bool> &visited,unordered_map<int,vector<int>> adj){
    visited[node]=true; //mark that node true in visited
    for(auto i:adj[node]){  //traverse through the children of node;
        if(!visited[i]){   //if the child is not visited, take its first child(i) as node, and parent as the current(parent) node and send in recursion
            bool cycle_ans=iscycledfs(i,node,visited,adj);
            if(cycle_ans){
                return true;
            }
        }
        else if(i!=parent){ //there can be only one case of cycle present, i.e the current child node is visited and it is not equal to parent
            return true;
        }
    }
    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //making adjlist from nodes and edges.
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int , bool> visited;  //visited check array

    for(int i=0;i<n;i++){  //checking all nodes,because there can be cases of disconnected graphs
        if(!visited[i]){ 
            bool ans=iscycledfs(i,-1,visited,adj);
            if(ans){ //if there is a cycle present
                return "Yes";
            }
        }
    }
    return "No";
}
