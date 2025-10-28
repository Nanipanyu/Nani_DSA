#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/network-delay-time/
// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj; 

        for(int i=0;i<times.size();i++){            
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            pair<int,int>p1 = make_pair(v,w);
            adj[u].push_back(p1);
        }
        vector<int> outdegree(n+1,0);                                              //to check if the starting node has any outgoing edge or not
        vector<int> time(n+1,INT_MAX);                                             //time vector to store the minimum time taken to reach each node from starting node
        for(int i = 1;i<=n;i++){
            for(auto j : adj[i]){
                outdegree[i]++;
            }
        }
        if(outdegree[k]==0){                                                          //if starting node has no outgoing edges, means it cannot reach any other node
            return  -1;
        }
        set<pair<int,int>> q;
        q.insert({0,k});
        time[k]=0;
        int lastprice = INT_MAX;                                                   //to store the maximum time taken to reach any node from starting node
        while(!q.empty()){
            auto top = *q.begin();
            int step = top.first;
            int node = top.second;
            q.erase(q.begin());
            lastprice = step;                                                      //updating the maximum time taken to reach any node from starting node, the last nodes being processed will have the maximum time(but if we had used Priprity queue(without deletion in the loop), we would have got wrong ans because a longer version to reach a node(which has been processed already) could be at the  pq)
            for(auto nei : adj[node]){
                if(time[nei.first]>step+nei.second){
                    if(q.find({time[nei.first],nei.first})!=q.end()){                  //if the node is already present in set(with a greaterdistance ), we need to remove it first before updating its time
                        q.erase({time[nei.first],nei.first});
                    }
                    int newtime = nei.second+step;
                    time[nei.first]=newtime;
                    q.insert({newtime,nei.first});
                }
            }
        }
        for(int i=1; i <= n; i++){                                  
            if(time[i]==INT_MAX){                                                       //if any node is unreachable, return -1
                return -1;
            }
        }
        return lastprice;
    }
};