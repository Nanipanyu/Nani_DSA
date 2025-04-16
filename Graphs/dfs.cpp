#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

void dfs(int node,vector<int> &component,unordered_map<int , bool> &visited,unordered_map<int , vector<int>> adjlist){
    component.push_back(node); //push the initial node to component(temp ans)
    visited[node]=true; //mark that node true in visited
    for(auto i:adjlist[node]){ //traverse through the children of node;
        if(!visited[i]){ //if the child is not visited, take its first child as node and send in recursion
            dfs(i,component,visited,adjlist); //this will cause to initailly capture the first child of each node(i.e traverse cyclically)
        }
    }

}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{   
    //V=no of nodes, E=no. of edges
    //Making adj list from given vertexes and nodes (edges)
    unordered_map<int , vector<int>> adjlist; 
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    unordered_map<int , bool> visited; //making a visited vector
    vector<vector<int>> ans; //to store final ans for dfs

    for(int i=0;i<V;i++){  //traversing through no. of nodes , because there can be cases of disconnected graphs
        if(!visited[i]){ //sending first node(i.e one cycle of graph will be solved)
            vector<int> component; //to store the ans of dfs for single cycle
            dfs(i,component,visited,adjlist);
            ans.push_back(component); //push the dfs traversal in final answer
        }
    }
    return ans;
}