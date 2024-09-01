#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print(string str){
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            str[i]='@';
        }
    }
    cout<<str;
}
int main(){
    string s;
    cout<<"Enter your sentence"<<" ";
    getline(cin,s);
    print(s);

    
}