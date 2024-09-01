#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &ans,int index,vector<int>&num){
        if(index>=num.size()){
            ans.push_back(num);
            return;
        }
        // swap(num[0],num[index]);
        for(int j=index;j<num.size();j++){
            // output.push_back(num[j]);
            // output.push_back(num[j]);
            swap(num[index],num[j]);
            solve(ans,index+1,num);
            swap(num[index],num[j]);
            // if(j<num.size()-1){
            //     swap(num[j],num[j+1]);
            // }
            // output.pop_back();
        }
    }
int main(){
        vector<int> num={1,2,3};
        vector<vector<int>> ans;
        // vector<int> output;
        int index=0;
        solve(ans,index,num);
        for(auto i:ans){
            cout<<"{";
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<"}"<<endl;
        }
        
    }
