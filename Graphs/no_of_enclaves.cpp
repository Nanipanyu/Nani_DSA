#include<iostream>
#include<vector>
#include<queue>
using namespace std;
  //https://leetcode.com/problems/number-of-enclaves/description/

  //You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> xdir = {0,0,1,-1};
        vector<int> ydir = {1,-1,0,0};
        queue<pair<int,int>> q;
        int ones = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    if(i==0 || i ==row-1 || j==0 || j==col-1){
                        grid[i][j]=2;
                        q.push({i,j});                                                     //pushing all the boundary 1's into queue(so we will use infection method) and marking them as 2 so that we don't visit them again,if they are connected to any other boundary 1's
                    }
                    else{
                        ones++;                                                             //counting total number of 1's which are not on boundary
                    }
                }
            }
        }
        if(ones == 0 && ones == row*col){
            return 0;
        }
        
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            int r = temp.first;
            int c = temp.second;
            for(int j=0;j<4;j++){
                int nx = xdir[j];
                int ny = ydir[j];
                if(r+nx<row && r+nx>-1 && c+ny <col && c+ny>-1 && grid[r+nx][c+ny]==1){                            //if any of the 1's connected to boundary 1's then mark them as 2 and push them into queue
                    grid[r+nx][c+ny]=2;
                    q.push({r+nx,c+ny});
                    ones--;                                                                                         //decrement the count of 1's which are not on boundary as they are connected to boundary 1's, and this will give you the count of 1's not connected to boundary 1's
                }
            }
        }
        return ones;
    }
};