#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/path-with-minimum-effort/

// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        set<pair<int,pair<int,int>>> q;
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> distance(row,vector<int>(col,INT_MAX));                          //distance matrix to keep track of maximum effort(height diff) from source to the current node along that route , suchh that this maximum effort is minimum among all other routes to reach that node
        q.insert({0,{0,0}});
        vector<int> xdir = {0,0,1,-1};
        vector<int> ydir = {1,-1,0,0};
        int maxi = -1;
        while(!q.empty()){
            auto top = *q.begin();                                                             //node(path) with minimum effort from source
            int effort = top.first;
            int x = top.second.first;
            int y = top.second.second;
            q.erase(q.begin());
            if(x==row-1 && y==col-1){                                                        //if we reach the destination cell return the effort
                return effort;
            }
            for(int i=0;i<4;i++){
                int nx = xdir[i];
                int ny = ydir[i];
                if(x+nx<row && x+nx>-1 && y+ny<col && y+ny>-1 ){
                    int neweffort = max(effort,abs(heights[x+nx][y+ny] - heights[x][y]));       //new effort will be maximum of current effort and the height difference of current cell and neighbour cell becuasee for a path the effort is defined as maximum height difference between two consecutive cells along that path
                    if(distance[x+nx][y+ny]>neweffort){                                        //if neweffort is less than the previously recorded effort to reach that neighbour cell from source along some other path, then only update it
                        if(distance[x+nx][y+ny]!=INT_MAX){                                      //if the neighbour cell is already present in set, then remove it first to update it with neweffort
                            q.erase({distance[x+nx][y+ny], {x+nx,y+ny}});                      
                        }
                        distance[x+nx][y+ny]=neweffort;                                         //update the effort to reach that neighbour cell from source
                        q.insert({neweffort,{x+nx,y+ny}});                                      //insert the neighbour cell with neweffort in set
                    }
                }
            }
        }
        return -1;
    }
};

//Basically we are using Dijkstra's algorithm here, but instead of sum of weights we are taking maximum of height diff(present in that path) along a path and minimizing that maximum height difference to reach the destination node
//For each path we are checking its max height diff(that maybe in the prev node along the path because thats the effort), and setting their distances as the effort , and while popping a node from set we are popping the node with minimum effort from source, and checking its neighbours to update their efforts if possible