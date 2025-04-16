// just to remind Dijkstra's is for undirected
#include <bits/stdc++.h> 
#include <unordered_map>
#include<vector>
#include<set>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {//vec has [x,y,w] x&y=neighbour(nodes) and w=weight of edge(distance)

     unordered_map<int,vector<pair<int,int>>> adj; //pair will have the neighbour and its edge weight(distance to that neighbour)

     //In this graph we also have weight in a edge which is similar to distance of the edge
    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        pair<int,int>p1 = make_pair(v,w);// so in adjList we are sending both the children(adj node) and weight(the distance of edge to that node)
        pair<int,int>p2 = make_pair(u,w);
        adj[u].push_back(p1);
        adj[v].push_back(p2);
    }

    vector<int> distance(vertices,INT_MAX); //distance vector of nodes from source node
    distance[source]=0; //set distance with itself 0

    set<pair<int, int>> st; //making a set where we will insert pair(distance from src node,current node)
    st.insert({0,source});

    while(!st.empty()) {
        auto top=*st.begin(); //take the element(E1) with shortest distance(form source node) from the set
        int topnode=top.second; //node with shortest distance from source(because we traversing first with the shordest distance of node Dijkstra’s greedy assumption is made  that once a node’s shortest distance is set, it cannot be updated/reached again mathematically.)
        int dist=top.first; //topnode distance
        st.erase(st.begin()); //pop E1
        for(auto neighbour:adj[topnode]){ //traverse through neighbour of topnode(E1 node)
            if(distance[neighbour.first]>dist+neighbour.second){  //if distance of neighbour from src:D1[distance[neighbour.first]] is greater than D2[distance of node from src + distance of node to neighbour], than D1 should be replaced by D2(shorter path), but below condition should be checked
                auto record = st.find(make_pair(distance[neighbour.first], neighbour.first)); //if the neighbour node  is already present in set than it should be removed first
                if (record != st.end()) {  //st.find returns an iterator if the pair is present ,if not it returns st.end
                    st.erase(record);
                }
                distance[neighbour.first]=dist+neighbour.second;  //distance updated
                st.insert(make_pair(distance[neighbour.first],neighbour.first)); //(distance , neighbour) is updated in set
            }
        }
    }
    return distance; //shortest path vector(distance vec has values of shortest distance from source node to each node)
}