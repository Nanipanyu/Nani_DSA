#include<bits/stdc++.h>
using namespace std;
void Sets(vector<string>&ans,string output,int index,string s){
    if(index>=s.length()){
        ans.push_back(output);
        return;
    }
    // exclude
    Sets(ans,output,index+1,s);
    // include
    char element=s[index];
    output.push_back(element);
    Sets(ans,output,index+1,s);
}
int main(){
    string s="Nani";
    vector<string>ans;
    string output="";
    int index=0;
    Sets(ans,output,index,s);
    for(auto i:ans){  
        cout<<'{' ;  
        for(auto j:i){
            cout<<j<<',';
        } 
        cout<<'}' <<endl;
    }
}