#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
  //https://leetcode.com/problems/is-graph-bipartite/description/

  //Given an undirected graph, return true if and only if it is bipartite.
  //A graph is bipartite if we can split its set of nodes into two independent subsets A and B such that every edge in the graph has its one node in A and another node in B.

  //so basically the problem is no two adjacent nodes should be in the same set

class Solution {
public:

    bool check(vector<vector<int>>& graph,int node,unordered_set<int> &odd,unordered_set<int> &even){
            odd.insert(node);                                                                //inserting the starting node in odd set
            queue<int> q;
            q.push(node);
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                for(int j=0;j<graph[temp].size();j++){                                        //bfs traversal of its neighbours
                    if(odd.count(temp)){                                                      //if the current node is in odd set 
                        if(odd.count(graph[temp][j])){                                        //if any of its neighbour is also in odd set then return false
                            return false;
                        }
                        else if(!even.count(graph[temp][j])){                                  //if the neighbour is not in odd set and not in even set then insert it into even set and push it into queue
                            even.insert(graph[temp][j]);
                            q.push(graph[temp][j]);
                        }
                    }
                    else{                                                                     //if the current node is in even set
                        if(even.count(graph[temp][j])){                                      //if any of its neighbour is also in even set then
                            return false;
                        }
                        else if(!odd.count(graph[temp][j])){                                 //if the neighbour is not in even set and not in odd set then insert it into odd set and push it into queue
                            odd.insert(graph[temp][j]);        
                            q.push(graph[temp][j]);
                        }
                    }
                }
            }
            return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> odd;                                        //to store the nodes in odd set
        unordered_set<int> even;                                      //to store the nodes in even set
        bool ans;
        
        for(int i=0;i<graph.size();i++){                                  //traversing all the nodes, because the graph may be disconnected
            if(!odd.count(i) && !even.count(i)){
                ans = check(graph,i,odd,even);
                if(!ans){
                    return false;
                }
            }
        }  
        return ans;      
    }
};