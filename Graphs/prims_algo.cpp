#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

//Prims algo is use to make minimum cost(weight) spanning tree from a undirected graph.
int mini(vector<int> &vec, vector<bool> &mst){
    int minIndex = -1, minValue = INT_MAX;
    for(int i = 1; i < vec.size(); i++){
        if(!mst[i] && vec[i] < minValue){ 
            minValue = vec[i]; 
            minIndex = i;
        }
    }
    return minIndex; // -1 if no valid node is found
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<int> key(n+1,INT_MAX); //key vector will store the weights of edges, initially set to inf
    vector<bool> mst(n+1,false); //
    vector<int> parent(n+1,-1); //will store the parents of node
    int count=0; //to trverse

    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        pair<int,int>p1 = make_pair(v,w);// so in adjList we are sending both the children(adj node) and weight(the distance of edge to that node)
        pair<int,int>p2 = make_pair(u,w);
        if(u!=v){
            adj[u].push_back(p1);
            adj[v].push_back(p2);
        }
    }
    int src=1;  //1 based indexing graph so staring from 1
    key[src]=0;  // marks it weight=0, i.e self weight=0
    parent[src]=-1; //it is starting node so it has no parent

    while(count!=n-1){  
        int mi=mini(key,mst); // find the index(node) with minimum weight in key
        mst[mi]=true; //mark the node/index wtih minimum weight true, after marked true it will further not get involved
        count++;

        //traverse through the children of node/index wtih minimum weight
        for(auto neighbour:adj[mi]){ 
            //if the child has not marked true in mst and weight between child and node is smaller than key[wight]
            if(mst[neighbour.first]==false && neighbour.second<key[neighbour.first]){
                key[neighbour.first]=neighbour.second; //replace the weight
                parent[neighbour.first]=mi;  //mark the children parent
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans; // storing our tree (u,v,weight)

    //traverse from 2nd because 1 parent is market -1 and it has no self weight 
    for(int i=2;i<=n;i++){
        pair<int,int>p1=make_pair(i,parent[i]);
        pair<pair<int,int>,int>p2=make_pair(p1,key[i]); //key[i] == its corresponding weight
        ans.push_back(p2);
    }
    return ans;
}
