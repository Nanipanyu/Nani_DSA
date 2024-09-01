#include<bits/stdc++.h>
using namespace std;
void solve(int arr[][4],vector<string> &ans,string output,int r,int c,int x,int y,int visited[][4]){
    if(x==(r-1)  && y==(c-1) ){
        ans.push_back(output);
        return;
    }
    visited[x][y]=1;
    if((y+1)<c && arr[x][y+1]==1 && visited[x][y+1] != 1 ){
        output.push_back('R');
        solve(arr,ans,output,r,c,x,y+1,visited);
        output.pop_back();
    } 
    if((y-1)>=0 && arr[x][y-1]==1 && visited[x][y-1]!=1){
        output.push_back('L');
        solve(arr,ans,output,r,c,x,y-1,visited);
        output.pop_back();
        
    } 
    if((x+1)<r && arr[x+1][y]==1 && visited[x+1][y]!=1){
        output.push_back('D');        
        solve(arr,ans,output,r,c,x+1,y,visited);
        output.pop_back();
    } 
    if((x-1)>=0 && arr[x-1][y]==1 && visited[x-1][y]!=1){
        output.push_back('U'); 
        solve(arr,ans,output,r,c,x-1,y,visited);
        output.pop_back();
    }  
    visited[x][y] = 0;
}
int main(){
    int num[4][4]={1,0,0,0,1,1,0,1,1,1,0,0,0,1,1,1};
    int visited[4][4]={0};
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cout<< visited[i][j];
    //     }
    //     cout<<endl;
    // }
    int r=4;
    int c=4;
    int x = 0;
    int y = 0;
    string output="";
    vector<string> ans;
    solve(num,ans,output,r,c,x,y,visited);
    for(auto i:ans){
        cout<<i<<" "<<endl;
    }
}
