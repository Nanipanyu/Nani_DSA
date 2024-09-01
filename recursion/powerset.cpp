#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int> >&ans,int index,vector<int> output,vector<int> V){
    if(index>=V.size()){
        ans.push_back(output);
        return;
    }
    // exclude
    solve(ans,index+1,output,V);
    // Include
    int element=V[index];
    output.push_back(element);
    solve(ans,index+1,output,V);
    // output.pop_back();
}


int main(){
   
    vector<int> V={6,2,1,5};
    vector<vector<int> >ans;
    vector<int>output;
    int index=0;
    solve(ans,index,output,V);
    cout<<"size"<<V.size()<<endl;
    for(auto i: ans){
        cout<<"{";
        for(auto j:i){
            cout<<j<<",";
        }
        cout<<"}"<<endl;
    }    
}