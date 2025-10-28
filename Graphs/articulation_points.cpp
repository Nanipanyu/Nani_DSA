#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

//Articulation point are nodes in graph that if remove them the graph spilts into two or more component
//We use DFS to find articulation points, it is very similar to Kruskals algo ,if(low[nbr]>=disc[node] && parent!=-1),here this consdion represents that if we remove the  node there different connection exist to neighour,
//which does not make the node a articulation point
void dfs(int node,unordered_map<int,vector<int>> &adj,vector<bool> &vis,
vector<int> &disc,vector<int> &low,int parent,int &timer,vector<bool> &ap){
    low[node]=disc[node]=timer++;
    vis[node]=true;
    int child=0;
    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        else if(!vis[nbr]){
            dfs(nbr,adj,vis,disc,low,node,timer,ap);
            low[node]=min(low[node],low[nbr]);
            if(low[nbr]>=disc[node] && parent!=-1){                                             //because if low[neighbour]<disc[node] , that means there is one more  way/node to reach neighbour(edge is not bridge) ,but if low[neighbour]>=disc[node] ,means there is only on way to reach the neighbour, hence it is a bridge edge
                ap[node]=true;
            }
            child++;
        }
        else{
            low[node]=min(low[node],disc[nbr]);
        }
    }
    if(parent==-1 && child>1){ //this condion is exception for starting node whose parent will always be-1(thats why our primary condition wont work through it), if it has more than 2 chains(child), then starting node is always a articulation point
        ap[node]=true;
    }
}

int main(){
    int n=5;
    int e=5;
    vector<pair<int,int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    unordered_map<int,vector<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer=0;
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    vector<bool> vis(n);
    vector<bool> ap(n,false);

    int parent=-1;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,disc,low,parent,timer,ap);
        }
    }
    cout<<"articulation points are:"<<" ";
    for(int i=0;i<ap.size();i++){
        if(ap[i]) cout<<i<<" ";
    }

}