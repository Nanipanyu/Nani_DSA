#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

class Solution {
  public:
  
    bool find(int posn,vector<int>& arr,vector<vector<int>> &dp,int sum){
        if(sum==0){                                                             //base case, if sum is 0, we found a subset with the given sum
            return true;
        }
        if(posn>=arr.size() || sum<0){
            return false;                                                       //out of bounds or sum negative, no valid subset
        }
        if(dp[posn][sum] != -1){
            return dp[posn][sum];
        }
        bool take = find(posn+1,arr,dp,sum-arr[posn]);                           // Option 1: Include the current element in the subset and move to the next element
        bool skip = find(posn+1,arr,dp,sum);                                     // Option 2: Exclude the current element and move to the next element
        return dp[posn][sum] = take || skip;                                     //return true if either including or excluding the current element leads to a valid subset
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>> dp(arr.size(), vector<int> (sum+1,-1));                //memoization table, both sum & position can vary
        return find(0,arr,dp, sum);
    }
};