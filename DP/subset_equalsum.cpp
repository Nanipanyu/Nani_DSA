#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/
// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

class Solution {
public:

    bool find(int posn,vector<int>& nums,vector<vector<int>> &dp,int sum,int &ans){
        if(sum == ans){                                                   //base case, if sum equals target num(i.e half of total sum), we found a valid subset
            return true;
        }
        if(posn>=nums.size() || sum<ans){                                 //out of bounds or sum less than target, no valid subset
            return false;
        }
        if(dp[posn][sum] != -1){
            return dp[posn][sum];
        }
        bool take = find(posn+1,nums,dp,sum-nums[posn],ans);              // Option 1: Include the current element in the subset and move to the next element
        bool skip = find(posn+1,nums,dp,sum,ans);                         // Option 2: Exclude the current element from the subset and move to the next element
        return dp[posn][sum] = take || skip;                              //return true if either including or excluding the current element leads to a valid subset
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for(int i=0;i<nums.size();i++){                                         //calculate total sum of elements
            sum = sum+nums[i];
        }    
        if(sum%2 != 0){                                                         //if sum is odd, we cannot partition it into two equal subsets
            return false;
        }  
        int ans = sum/2;                                                        //target sum for each subset ,half of total sum
        vector<vector<int>> dp(nums.size() , vector<int> (sum+1,-1));
        return find(0,nums,dp,sum,ans);  
    }
};