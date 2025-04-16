#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

bool topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //preparing adjacency list
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    // preparing indegree vector
    vector<int> indegree(v);
    for(auto i:adj){
        // increase the indegree based on no. of parents
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    queue<int> q; 
    int count=0;

    //if a node indegree is 0(i.e no parents(first node)) then push it in queue.
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }


    while(!q.empty()){
        int front=q.front();
        q.pop();
        count++;
        for(auto i:adj[front]){
            //as a node has been put inside queue/ans decrease the indegree of their children
            indegree[i]--;
            if (indegree[i] == 0) {// if indegree has become 0 then push it to queue and ans
                q.push(i);
            }
        }

    }

    if(count==v){ //since kahns alg(toposort) works only on directed acyclic graph so if , count=no. of nodes, that means kahns works i.e it is directed acyclic
        return false;
    }
    else{ //well if count != no.of nodes, that means kahn(toposort) does not work, i.e there is cycle, count will bw less than v,queue will become empty and not all nodes will be processed
        return true;
    }
}