#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
// template <typename T> :to not declare the datatype
using namespace std;

bool iscycledfs(int node,unordered_map<int,bool> &visited, 
unordered_map<int,bool> &visdfs, unordered_map<int,vector<int>> &adj){
  visited[node]=true; 
  visdfs[node]=true;
    for(auto i:adj[node]){ 
      if(!visited[i]){
        bool cycle_ans=iscycledfs(i,visited,visdfs,adj);
        if(cycle_ans){
          return true;
        }
      }
      else if(visdfs[i]){ //if both visited and dfsvisited is true for a node(that node has found itself once again in the recursion tree) cycle is present
        return true;
      } 
  }
  visdfs[node]=false;                                      //backtracking step: when we are leaving the node after all its children have been processed, mark it false in visdfs, so that if the this nodes come back in another dfs call, it is not part of that dfs cycle
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
    }
    unordered_map<int,bool> visited;
    unordered_map<int,bool> visdfs;                                                              //to check if the node is visited in the current dfs call or not, to differentiate actual cycle and cross edge
    for(int i=0;i<n;i++){  //checking all nodes,because there can be cases of disconnected graphs
        if(!visited[i]){ 
            bool ans=iscycledfs(i,visited,visdfs,adj);
            if(ans){ //if there is a cycle present
                return 1;
            }
        }
    }
    return 0;
}