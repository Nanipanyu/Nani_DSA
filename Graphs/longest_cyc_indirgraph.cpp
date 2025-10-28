#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>    
using namespace std;

//You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

//https://leetcode.com/problems/longest-cycle-in-a-graph/description/

class Solution {
public:
    void dfs(int node,vector<bool> &visited,vector<bool> &visitdfs,unordered_map<int,vector<int>> &adj,int &maxi,int count,
    unordered_map<int,int> &strt){
        visited[node]=true;
        visitdfs[node]=true;
        if(strt.count(node) == 0){                                       //if the node is not present in strt map(not been visited), then only
            strt[node]=count;                                            //store the count at which the node is first visited in the current dfs call
        }
        for(auto j: adj[node]){
            if(!visited[j]){
                dfs(j,visited,visitdfs,adj,maxi,count+1,strt);
            }
            else if(visitdfs[j]){                                          //if cycle is present
                count++;                                                   //to include the last node in the cycle
                maxi = max(maxi,count-strt[j]);                            //updating the maximum length of the cycle found so far by finding the difference of current count and the count at which the node(j) is first visited in the current dfs call
                visitdfs[node]=false;                                      //backtracking step
                return;
            }
        }
        visitdfs[node]=false;                                              //   backtracking step: when we are leaving the node after all its children have been processed, mark it false in visdfs, so that if the this nodes come back in another dfs call, it is not part of that dfs cycle
    }

    int longestCycle(vector<int>& edges) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> strt;                                              //to store the count at which the node is first visited in the current dfs call
        for(int i=0;i<edges.size();i++){
            if(edges[i]!= -1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<bool> visited(edges.size(),false);
        vector<bool> visdfs(edges.size(),false);                                     //to check if the node is visited in the current dfs call or not, to differentiate actual cycle and cross edge
        int maxi = -1;                                                             //to store the maximum length of the cycle found
        for(int i=0;i<edges.size();i++){  
            if(!visited[i]){ 
                dfs(i,visited,visdfs,adj,maxi,0,strt);
            }
        }  
        return maxi; 
    }
};