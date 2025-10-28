#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-falling-path-sum/
//Given a square array of integers matrix, we want the minimum sum of a falling path through matrix.
//A falling path starts at any element in the first row and chooses one element from each row. The next row's choice must be in a column that is different from the previous row's column by at most one.


class Solution {
public:
    int findmini(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0 || j>=matrix[0].size() || i<0){                             //out of bounds take maximum value so that this path is not considered
            return INT_MAX;
        }
        if(i==0){                                                          //base case, reached first row , return value at that position
            return matrix[i][j];
        }
        
        if(dp[i][j] != -1){                        
            return dp[i][j];
        }
        int left = findmini(i-1,j-1,matrix,dp);                             //moving left diagonal up to find min path sum
        int mid = findmini(i-1,j,matrix,dp);                                //moving straight up to find min path sum
        int right = findmini(i-1,j+1,matrix,dp);                            //moving right diagonal up to find min path sum
        return dp[i][j] = matrix[i][j] + min(left,min(mid,right));          //min path sum to reach this cell is value at this cell + min of left, mid and right in upwards direction   
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        int mini = INT_MAX;
        for(int j = 0;j<col;j++){                                              //try for every col element in last row , by moving upwards ,and take the minimum among them
            mini = min(mini,findmini(row-1,j,matrix,dp));
        }
        return mini;
    }
};