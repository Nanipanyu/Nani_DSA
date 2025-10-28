#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-falling-path-sum-ii/
//Given a square array of integers matrix, we want the minimum sum of a falling path through matrix.
//A falling path starts at any element in the first row and chooses one element from each row. The next row's choice must be in a different column than the previous row's column.
//we must find the minimum sum of such a falling path.

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
        int temp = INT_MAX;
        for(int k = 0;k < matrix[0].size();k++){                           //try for every column in the previous row except the current column j
            if(k!=j){
                temp = min(temp,findmini(i-1,k,matrix,dp));                //moving upwards to find min path sum,take the minimum among all columns except j
            }
            else{
                continue;
            }
        }   
        return dp[i][j] = matrix[i][j] + temp;                             //while moving downwards , min path sum to reach this cell is value at this cell + min of all columns except j in upwards direction
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        int mini = INT_MAX;
        for(int j = 0;j<col;j++){                                       //try for every col element in last row , by moving upwards ,and take the minimum above path among them                                         
            mini = min(mini,findmini(row-1,j,grid,dp));
        }
        return mini;
    }
};