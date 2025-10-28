#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/house-robber/
//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

class Solution {
public:
    //Here just robbing alternate houses won't work, we need to check for the neighbouring house of alternate houses as well to get the maximum amount that can be robbed

    int robfrom(int i,vector<int> &dp,vector<int> &nums){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int rob = nums[i] + robfrom(i+2,dp,nums);                   // Option 1: Rob the current house and move to the house after next
        int skip = robfrom(i+1,dp,nums);                            // Option 2: Skip the current house and move to the next house
        return dp[i]=max(rob,skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1); 
        return robfrom(0,dp,nums);                                    //get the max amount that can be robbed starting from house 0 using recursion with memoization                                      
    }
};