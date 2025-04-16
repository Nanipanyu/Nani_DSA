#include<iostream>
#include<unordered_map>
#include<stack>
#include<queue>
#include<vector>
#include <bits/stdc++.h> 
using namespace std;

class Graph{
    public:
    unordered_map<int,vector<pair<int,int>>> adj; //pair will have the neighbour and its edge weight(distance to that neighbour)

    void addEdge(int u,int v,int weight){  //In this graph we also have weight in a edge which is similar to distance of the edge
        pair<int,int>p = make_pair(v,weight);// so in adjList we are sending both the children(adj node) and weight(the distance of edge to that node)
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto &i:adj){
            cout<<i.first<<"->";
            for(auto &j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }cout << endl;
        }
    }

    //topological sort
    void toposort(int node,stack<int> &s,unordered_map<int , bool> &visited){
        visited[node]=true;
        for(auto neighbour:adj[node]){
            if (!visited[neighbour.first]) {
              toposort(neighbour.first, s, visited);
            }
        }
        //as ones node children is over, before returning place it in stack.(we want to fill the last nodes(in directed graph) in stack first)
        s.push(node);
        return;
    }

    //shortestpath function which will have a vector which will the shortest path for source till each node
    void getshortestpath(queue<int> &q,vector<int> &distance,int &flag,int src){
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node==src){ 
                flag=1;
            }
            if(flag!=0){ //until we have not reached src i.e(nodes before src which dont have path from src) keep their distance INF
                for(auto i:adj[node]){ //traverse through nodes neighbours
                    if(distance[i.first]>distance[node]+i.second){ //if the current distance of neighbour(in distance vec)(D1) is bigger than dist of node(in node vector)+ its edge weight(D2), than D2 is the shorter path and better option
                        distance[i.first]=distance[node]+i.second; //replace with D2
                    }
                }
            }
        }
    }
    

};

int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    int v=6;

    unordered_map<int , bool> visited;
    stack<int> s; 
    for(int i=0;i<v;i++){ //traverse through each unvisited node(due to seperated graphs)
        if(!visited[i]){ 
            g.toposort(i,s,visited);
        }
    }

    queue<int> q;
    //fill the q from stack in lifo order
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    int src=1 ;//staring node(from which each distances will be found)
    vector<int> distance(v);

    // initially set all the distance to INF
    for(int i=0;i<v;i++){
        distance[i]=INT_MAX;
    }
    distance[src]=0; 
    int flag=0; //to keep a check if src node is reached in traversing
    g.getshortestpath(q,distance,flag,src);

    //distance vector will have the values of shortest path to all nodes.
    for(int i=0;i<distance.size();i++){
        cout<<distance[i]<<" ";
    }
}
