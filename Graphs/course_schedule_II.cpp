#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;

//https://leetcode.com/problems/course-schedule-ii/
//For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
//Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

//here the solution is to check whether there is cycle in directed graph or not, if there is cycle then we cannot finish all courses, if there is no cycle we can find a course ordering using toposort
class Solution {
public:

    void dfs(int node,unordered_map<int , bool> &visited,unordered_map<int,vector<int>> &adj,
    unordered_map<int , bool> &visitdfs,stack<int> &s){
        visited[node]=true;
        visitdfs[node]=true;
        for(auto j:adj[node]){
            if(!visited[j]){
                dfs(j,visited,adj,visitdfs,s);
            }
            else if(visitdfs[j]){
                return;
            }
        }
        visitdfs[node]=false;
        s.push(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        unordered_map<int , bool> visited;
        unordered_map<int , bool> visitdfs;
        stack<int>s;
        vector<int> ans;

        for(int i=0;i<numCourses;i++){ //traverse through each unvisited node(due to seperated graphs)
            if(!visited[i]){ 
                dfs(i,visited,adj,visitdfs,s);
            }
        }
        if(s.size()!=numCourses){
            return ans;
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};