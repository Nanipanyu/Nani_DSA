#include<iostream>
#include<stack>
using namespace std;
int main(){
    // stack has a property of reversing data
    string s="Panyu";
    stack<char> ans;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        ans.push(ch);
    }
    string rev=" ";
    while(!ans.empty()){
        char ch=ans.top();
        rev.push_back(ch);
        ans.pop();
    }
    cout<<"ans is"<<rev<<endl;
}