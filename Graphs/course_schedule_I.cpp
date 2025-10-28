#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//https://leetcode.com/problems/course-schedule/

//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

//here the solution is to check whether there is cycle in directed graph or not, if there is cycle then we cannot finish all courses, so we can use dfs based cycle detection in directed graph

class Solution {
public:

    void dfs(int node,unordered_map<int , bool> &visited,unordered_map<int,vector<int>> &adj,
    unordered_map<int , bool> &visitdfs,bool &hascycle){
        visited[node]=true;
        visitdfs[node]=true;
        for(auto j:adj[node]){
            if(!visited[j]){
                dfs(j,visited,adj,visitdfs,hascycle);
            }
            else if(visitdfs[j]){
                hascycle =true;
                return;
            }
        }
        visitdfs[node]=false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        unordered_map<int , bool> visited;
        unordered_map<int , bool> visitdfs;
        bool hascycle = false;

        for(int i=0;i<numCourses;i++){ //traverse through each unvisited node(due to seperated graphs)
            if(!visited[i]){ 
                dfs(i,visited,adj,visitdfs,hascycle);
                if(hascycle){
                    return false;
                }
            }
        }
        return true;
    }
};