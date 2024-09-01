#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
void maxcount(string s){
    int num[26]={0};
    
    for(int i=0;i<s.length();i++){
        int count=0;
        if(s[i]<='z' && s[i]>='a'){
            count=s[i]-'a';
        }
        else{
            count=s[i]-'A';
        }
        num[count]++;
    }
    int hi=0;
    int j=0;
    for(int i=0;i<26;i++){
        hi=max(num[i],hi);
        if(num[i]==hi){
            j=i;
        }
    }
    char temp='a' + j;
    cout<<"max letter occured"<<" "<<temp <<endl;
    cout<<"its frequency"<<hi;

}
int main(){
    string M;
    cout<<"Enter your string"<<" ";
    cin>>M;
    maxcount(M);
}

// int main(){
//     cout<<"Enter your character";
//     string s;
//     // cin.getline(name,20);
//     cin>>s;
//     cout<<s;
// }