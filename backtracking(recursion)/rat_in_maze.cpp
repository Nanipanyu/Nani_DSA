#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

//function to check if the next step is safe or not(it must be within the matrix)(it should not be visited) & (arr[][]==1, so that there is a path)
bool issafe(int x, int y, vector<vector<int>> &arr, int n,vector<vector<bool>> &visited){
    if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0) && (arr[x][y]==1)){
        return true;
    }
    else{
        return false;
    }
}

void solve(int x,int y,vector<vector<int>> &arr,int n,vector<vector<bool>> &visited,string path,vector<string> &ans){
    if(x==n-1 && y==n-1){  //base case : if our rat has reached end of matrix
        ans.push_back(path); //store the current path taken in ans
        return;
    }
    //movements - D,L,R,U
    if(issafe(x+1,y,arr,n,visited)){ //check if it is safe to go down
        visited[x][y]=1;  //before going down mark that box visited, i.e visited[][]=1
        solve(x+1,y,arr,n,visited,path+'D',ans); //going down and finding next path
        visited[x][y]=0;   // when backtracking set the current visitedbox to unvisited (i.e visited[][]=0) so that new path can be found

    }
    if(issafe(x,y-1,arr,n,visited)){ //check if it is safe to go left
        visited[x][y]=1;   //before going left mark that box visited, i.e visited[][]=1
        solve(x,y-1,arr,n,visited,path+'L',ans); //going left and finding next path
        visited[x][y]=0;  // when backtracking set the current visitedbox to unvisited (i.e visited[][]=0) so that new path can be found
    }
    if(issafe(x,y+1,arr,n,visited)){ //check if it is safe to go right
        visited[x][y]=1;
        solve(x,y+1,arr,n,visited,path+'R',ans);
        visited[x][y]=0;
    }
    if(issafe(x-1,y,arr,n,visited)){ //check if it is safe to go up
        visited[x][y]=1;
        solve(x-1,y,arr,n,visited,path+'U',ans);
        visited[x][y]=0;
    }
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<vector<bool> > visited(n,vector<bool>(n,0)); //visited array , will help in finding multiple paths, same dim as arr, and all val set to 0 initially
    string path="";
    vector<string> ans; //vector of multiple possile path
    if(arr[0][0]==0){
        return ans;
    }
    solve(0,0, arr, n ,visited,path,ans); //finding all possible path
    return ans;
}