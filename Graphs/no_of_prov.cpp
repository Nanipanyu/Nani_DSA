#include<iostream>
#include<vector>
using namespace std;    

//There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// so basically it is a typical dfs/bfs question asking how many disconnected nodes are there

class Solution {
public:

    void dfs(int i,vector<bool> &visited,vector<vector<int>>& isConnected){
        visited[i]=true;
        for(int j=0;j<isConnected.size();j++){
            if(!visited[j] && isConnected[i][j]==1){
                dfs(j,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(),false);
        int province = 0;
        for(int i = 0;i<isConnected.size();i++){
            if(!visited[i]){
                dfs(i,visited,isConnected);
                province++;
            }
        }
        return province;
    }
};