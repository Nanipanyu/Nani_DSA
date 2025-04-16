#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    //s=starting node, t=end node of path, n=no. of nodes ,m=no.of edges
	
	unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){ //adjacency list
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(n+1,0);//visited array,(n+1) because staartin node is 1
	vector<int> parent(n+1,-1);//parent array,(n+1) because staartin node is 1
	queue<int> q;
	q.push(s);
	visited[s] = 1;

    //BFS
	while(!q.empty()){ //traverse till queue reaches an empty state
		int front=q.front();// take new front from queue
		q.pop();//pop the front ele
        for(int i=0;i<adj[front].size();i++){ //traverse through the size of children of front
            if(visited[adj[front][i]]!=0){
                continue;//if the children is visited then pass
            }
            else{  //if not (i)mark its parent  (ii)mark it visited  (iii)push the children in queue so that we will traverse through chidren next
                visited[adj[front][i]]=1;
				parent[adj[front][i]]=front;
                q.push(adj[front][i]);
            }
        } 
    }
	int curr=t;
	vector<int> path; //will store the shortest path between s node and t node.
	while(curr!=-1){ //we will get the shortest path by following the parent from t node till we reach to s node
		path.push_back(curr);
		curr=parent[curr];
	}

    //since the shortest path was stored in reversed , we need to reverse it
	reverse(path.begin(), path.end());
	return path;
}