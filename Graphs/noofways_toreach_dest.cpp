#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
// Return the number of ways you can arrive at your destination in the shortest amount of time.

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        unordered_map<int,vector<pair<int,int>>> adj; 
        int MOD = 1e9 + 7;
        for(int i=0;i<roads.size();i++){            
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<long long> time(n,LLONG_MAX);                                          //to store the minimum time taken to reach each node from starting node
        vector<long long> count(n,0);                                                 //to store the number of ways to reach each node from starting node in minimum time
        set<pair<long long,int>> q;
        q.insert({0,0});
        time[0]=0;
        count[0]=1;                                                                   //starting node can be reached in 1 way
        while(!q.empty()){
            auto top = *q.begin();
            long long step = top.first;
            int node = top.second;
            q.erase(q.begin());                                                       
            for(auto nei : adj[node]){
                if(time[nei.first]>step+nei.second){                                  //found a shorter way to reach nei.first
                    long long newtime = nei.second+step;
                    time[nei.first] = newtime;                                        //updating the minimum time to reach nei.first
                    count[nei.first]=count[node]%MOD;                                 //updating the number of ways to reach nei.first , count vector is needed because there can be multiple ways to reach nei.first in the same minimum time , you can test this test case[[0,2,1],[0,1,1],[1,3,1],[2,3,1],[3,3,1]], this test case fails if we dont use count vector
                    q.insert({newtime,nei.first});                                    //inserting nei.first in set with its updated minimum time 
                }
                else if(time[nei.first]==step+nei.second){                            //found another way to reach nei.first in the same minimum time
                    count[nei.first] = (count[nei.first]+count[node])%MOD;            //updating the number of ways to reach nei.first by adding the number of ways to reach current node
                }
            }
        }
        return count[n-1]%MOD;
    }
};