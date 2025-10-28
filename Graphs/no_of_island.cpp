#include<iostream>
#include<vector>
#include<queue>
using namespace std;
  //https://leetcode.com/problems/number-of-islands/description/

  //Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
  //An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> q;
        queue<pair<int,int>> next;
        vector<int> xDir = {0,0,1,-1};
        vector<int> yDir = {1,-1,0,0};
        int island = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='2';
                    q.push({i,j});
                    island++;
                }
                while(!q.empty()){
                    pair<int,int> temp = q.front();
                    int r = temp.first;
                    int c = temp.second;
                    q.pop();
                    for(int j = 0;j<4;j++){
                        int nx = xDir[j];
                        int ny = yDir[j];
                        if(r+nx>-1 && r+nx<row && c+ny>-1 && c+ny<col && grid[r+nx][c+ny]=='1'){
                            grid[r+nx][c+ny]='2';
                            q.push({r+nx,c+ny});
                        }        
                    }
                }
            }
        }
        return island;
    }
};