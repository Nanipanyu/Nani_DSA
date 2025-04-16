#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;

#include <bits/stdc++.h> 

void toposort(int node,stack<int> &s,unordered_map<int , bool> &visited,unordered_map<int,vector<int>> &adj){
    visited[node]=true;
    for(auto i:adj[node]){
        if (!visited[i]) {
          toposort(i, s, visited, adj);
        }
    }
    //as ones node children is over, before returning place it in stack.(we want to fill the last nodes(in directed graph) in stack first)
    s.push(node);
    return;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // making adjacency list
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    unordered_map<int , bool> visited;
    stack<int> s; 

    for(int i=0;i<v;i++){ //traverse through each unvisited node(due to seperated graphs)
        if(!visited[i]){ 
            toposort(i,s,visited,adj);
        }
    }
    vector<int> ans;
    //fill the ans vector from stack in lifo order
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}