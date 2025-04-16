#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
// template <typename T> :to not declare the datatype
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    unordered_map<int,bool> visited; //to keep a check if a node and its children(node) has been visited or not
    vector<int> ans; //storing bfs order
    queue<int> q; //queue to store the node and its children which will help in traversing
    for(int i=0;i<n;i++){ //initially setting every node not visited
        visited[i]=false;
    }
    q.push(0); //pushing the initial element in queue
    int front=q.front(); //front = first element/next ele
    visited[front]=true; //mark first ele=true
    ans.push_back(front); //push first ele in ans
    while(!q.empty()){ //traverse till queue reaches an empty state
        for(int i=0;i<adj[front].size();i++){ //traverse through the size of children of front
            if(visited[adj[front][i]]){
                continue;//if the children is visited then pass
            }
            else{  //if not (i)store it in ans  (ii)mark it visited  (iii)push the children in queue so that we will traverse through chidren next
                ans.push_back(adj[front][i]);
                visited[adj[front][i]]=true;
                q.push(adj[front][i]);
            }
        }
        q.pop(); //pop the front ele
        front=q.front(); // take new front from queue
    }
    return ans;
}