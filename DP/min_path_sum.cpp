#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-path-sum/
//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

class Solution {
public:
    int find(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==0 && j==0){                                                        //base case, reached start , return value at start
            return grid[i][j];
        }
        if(i<0 || j<0){
            return INT_MAX;                                                      //out of bounds, return max value so that this path is not considered
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = find(i-1,j,grid,dp);                                            //moving up to find min path sum
        int left = find(i,j-1,grid,dp);                                         //moving left to find min path sum
        return dp[i][j] = grid[i][j] + min(up,left);                            //min path sum to reach this cell is value at this cell + min of up and left
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        return find(row-1,col-1,grid,dp);
    }
};