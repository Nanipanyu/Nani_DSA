#include<iostream>
#include<vector>
#include<queue>
using namespace std;
  //https://leetcode.com/problems/01-matrix/description/
  //Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
  //The distance between two cells sharing a common edge is 1.
  
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<int> Xdir = {0,0,1,-1};
        vector<int> Ydir = {1,-1,0,0};
        vector<vector<int>> ans = mat;
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int,int>> q;
        int ones=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else if(mat[i][j]==1){
                    ones++;
                }
            }
        }
        if(ones==0 || ones== row*col){
            return ans;
        }
        int time = 0;
        while(!q.empty()){
            time++;
            int size =q.size();
            for(int i=0;i<size;i++){
                pair<int,int> curr = q.front();
                q.pop();
                int r =curr.first;
                int c = curr.second;
                for(int j=0;j<4;j++){
                    int nx = Xdir[j];
                    int ny = Ydir[j];
                    if(r+nx < row && r+nx >-1 && c+ny < col && c+ny >-1){
                        if(mat[r+nx][c+ny]==1){
                            mat[r+nx][c+ny]=0;
                            q.push({r+nx,c+ny});
                            ans[r+nx][c+ny]=time;
                            ones--;
                        }
                        if(ones==0){
                            return ans;
                        }
                    }
                }
            }
        }
        return ans;
    }
};