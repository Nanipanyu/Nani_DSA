#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int solve(vector<int>& cost,int n , vector<int> &costwithstep){
            if(n==0){
                return cost[0];
            }
            if(n==1){
                return cost[1];
            }
            if(costwithstep[n]!=-1){
                return costwithstep[n];
            }
            costwithstep[n] = cost[n]+min(solve(cost,n-1,costwithstep),solve(cost,n-2,costwithstep));
            return costwithstep[n];
        }
    
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            vector<int> costwithstep(n,-1);
            int ans = min(solve(cost,n-1,costwithstep),solve(cost,n-2,costwithstep)); //because cost[n] has no cost/value(we cant do cost[n]+ min((n-1path),(n-2path)), but to reach n ways:(n-1),(n-2), so we have to check the min path among two 
            return ans;
        }
    };