#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/shortest-path-in-binary-matrix/
// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> xdir = {0,0,1,-1,1,-1,-1,1};                     //8 directions
        vector<int> ydir = {1,-1,0,0,1,-1,1,-1};
        vector<vector<int>> distance(row, vector<int>(col, 1));      //distance matrix to keep track of distance from source to each cell initially all cells are marked with 1, as the minimum distance can be 1(when source and destination are same)
        queue<pair<int,int>> st;
        if(grid[0][0]==1){
            return -1;
        }
        if(row==1 && col==1 && grid[0][0]==0){
            return 1;
        }
        st.push({0,0});
        grid[0][0]=2;
        while(!st.empty()){                                                            //standard bfs
            pair<int,int>  top = st.front();
            int x = top.first;
            int y = top.second;
            st.pop();
            for(int j=0;j<8;j++){                                                      //traversing in 8 directions                
                int nx = xdir[j];
                int ny = ydir[j];
                if(x+nx<row && x+nx>-1 && y+ny<col && y+ny>-1 ){
                    if(x+nx==row-1 && y+ny==col-1){                                   //if we reach the destination cell return the distance of current cell +1
                        if(grid[x+nx][y+ny]==0){
                            return distance[x][y]+1;
                        }
                        return -1;
                    }
                    if(grid[x+nx][y+ny]==0){
                        st.push({x+nx,y+ny});
                        distance[x+nx][y+ny] = distance[x][y]+1;
                        grid[x+nx][y+ny]=2;
                    }
                    
                }

            }
        }
        return -1;
    }
};