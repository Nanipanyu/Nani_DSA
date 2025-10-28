#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/unique-paths/
//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//How many possible unique paths are there?

class Solution {
public:

    int solve(int i,int j,vector<vector<int>> &dp){
        if(i==0 && j==0){                                                 //base case, reached start , return 1 way
            return 1;
        }
        if(i<0 || j<0){                                                    //out of bounds
            return 0; 
        }
        if(dp[i][j]!=-1){                                                   //memoization
            return dp[i][j];
        }
        int up = solve(i-1,j,dp);                                           //moving up to find ways
        int left = solve(i,j-1,dp);                                       //moving left to find ways
        return dp[i][j] = up+left;                                        //total ways to reach this cell is sum of ways from up and left 
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);                                       //start with bottom right corner and move to top left corner, and count the number of ways to reach there
    }
};