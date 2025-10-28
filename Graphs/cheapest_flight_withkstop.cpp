#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
//Cheapest Flights Within K Stops
// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {                 //k= stops i.e no. of nodes in between src and dst, thats why price vector is of size k+2
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }
        vector<vector<int>> price(n,vector<int> (k+2,INT_MAX));                                             //price vector to store the min price of reaching a node with certain stops, we are taking stops into consideration(because take example dest=2 but 1 comes before that ) to reach 1 there is a 2 path , if we go with the cheaper path(and if later 1 gets popped out,its price is set to minimum) and after that we find that reaching 2 exceeds k stops(which is useless), then node with expensive path is better(if we can reach dest within k stop) but when 1 comes through the longer path we cant update its price , becuase it is expensive
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,src,0});                                                                                //{cost,node,stop}
        while(!pq.empty()){
            auto curr = pq.top();
            int cost = curr[0];
            int node = curr[1];
            int stop = curr[2];
            if(node==dst){
                return cost;
            }    
            pq.pop();
            if(stop<=k){                                                                                    //if stop>k then we cant go further
                for(auto nei : adj[node]){
                    if(price[nei.first][stop+1] > cost+nei.second){                                         //if we can reach nei node with stop+1 with lesser cost then only we will push it to pq
                        price[nei.first][stop+1]=cost+nei.second;
                        pq.push({cost+nei.second,nei.first,stop+1});
                    }
                }
            }
        }
        return -1;
    }
};