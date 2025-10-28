#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;
 
//SCC:Strongly connected components, are those components in graph in which you start from any node , you will be able to traverse every node in the component

void dfs(int node,stack<int> &st,vector<bool> &vis,unordered_map<int,vector<int>> &adj){
	vis[node]=true;
	for(auto nbr:adj[node]){
		if(!vis[nbr]){
			dfs(nbr,st,vis,adj);
		}
	}
	st.push(node);                                                    //remember to push after all its neighbour have been visited, so that in transpose graph we can start from node which finished last
	return;
}

void dfstranspose(int node,vector<bool> &vis,unordered_map<int,vector<int>> &adj,int &ans){
	vis[node]=true;
	for(auto nbr:adj[node]){
		if(!vis[nbr]){
			dfstranspose(nbr,vis,adj,ans);
		}
	}
	return;
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	unordered_map<int,vector<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}
	vector<bool> vis(v,false);
	stack<int> st;

    //Topsorting our graph, so we would traverse in this order in seconddfs(counting SCC)
	for(int i=0;i<v;i++){
		if(!vis[i]){
			dfs(i,st,vis,adj);
		}
	}

	//transpose adjacency list( edges reversed)
	unordered_map<int,vector<int>> transpose;
	for(int i=0;i<v;i++){
		for(auto nbr:adj[i]){
			transpose[nbr].push_back(i);
		}
	}
	vector<bool> newvis(v,false);

	int ans=0; //count SCC

    //travesing in toposort order in our graph after reversing edges
	while(!st.empty()){
		int node=st.top();
		st.pop();
		if(!newvis[node]){
			ans++; //every time node neighbour has finished increased SCC,
			dfstranspose(node,newvis,transpose,ans);
		}
	}
	return ans;
}