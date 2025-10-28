#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> dirX = {0, 0, 1, -1};                               // Direction vectors for 4-directional movement
        vector<int> dirY = {1, -1, 0, 0};                               // Direction vectors for 4-directional movement
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;                                           // Count fresh oranges, because if no fresh oranges present then -1
                }
            }
        }
        if(fresh == 0){
            return 0;
        }
        if(fresh == row*col){
            return -1;
        }
        int minutes = -1;
        while(!q.empty()){
            minutes++;                                                         //increment minutes for each level of BFS
            int size = q.size();
            for(int k=0;k<size;k++){                                          // Iterate through all rotten oranges for this minute
                pair<int,int> temp = q.front();
                q.pop();
                for(int i = 0;i<4;i++){                                       // for each rotten orange traverse all 4 directions
                    if(temp.first + dirX[i]<row && temp.first + dirX[i]>-1 && temp.second + dirY[i]<col && temp.second + dirY[i]>-1){          //if position is within grid bounds
                        if(grid[temp.first+dirX[i]][temp.second+dirY[i]]==1){                                                                   //if fresh orange
                            q.push({temp.first+dirX[i],temp.second+dirY[i]});
                            grid[temp.first+dirX[i]][temp.second+dirY[i]]=2;                                                                   //mark as rotten
                            fresh--;
                        }
                    }
                }
            }
            if(fresh==0){
                break;
            }
            
        }
        return (fresh==0)? minutes : -1;
    }
};