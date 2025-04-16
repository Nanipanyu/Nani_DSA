#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
// template <typename T> :to not declare the datatype
using namespace std;

bool iscycledfs(int node,unordered_map<int , bool> &visited,unordered_map<int,vector<int>> adj){
    queue<int> q;
    unordered_map<int , int> parent;
    parent[node]=-1; //setting the first node parent as -1
    visited[node]=1; //setting the first node  as visited
    q.push(node);  
    while(!q.empty()){
        int front=q.front(); 
        q.pop();
        for(auto neighbour:adj[front]){  //going for all the childs of a node 
            if(visited[neighbour]==true && neighbour!=parent[front]){ //condition for cycle present
                return true;
            }
            else if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour]=true;
                parent[neighbour]=front;
            }
        }
    }
    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){ //adjacency list
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int , bool> visited; 

    for(int i=0;i<n;i++){  
        if(!visited[i]){ 
            bool ans=iscycledfs(i,visited,adj);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";
}
