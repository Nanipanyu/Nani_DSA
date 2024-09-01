#include<bits/stdc++.h>
using namespace std;
void solve(vector<string> &ans,string output,int index,string mapping[],string num){
    if(num.length() ==0){
        return;
    }
    if(index>=num.length()){
        ans.push_back(output);
        return;
    }
    int i=num[index]-'0';
    string value=mapping[i];
    for(int j=0;j<value.length();j++){
        output.push_back(value[j]);
        solve(ans,output,index+1,mapping,num);
        output.pop_back();
        }

    }



int main(){
    string num="234";
    vector<string> ans;
    string output="";
    int index=0;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(ans,output,index,mapping,num);
    for(auto i:ans) cout<<i<<" ";
}