#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string compress(string s){
    int num[26]={0};
    int count=0;
    for(int i=0;i<s.length();i++){
        count=s[i]-'a';
        num[count]++;

    }
    string temp;
    for(int j=0;j<26;j++){
        if(num[j]!=0 && num[j]!=1){
            char t='a'+j;
            temp.push_back(t);
            char d='0'+num[j];
            temp.push_back(d);
        }
        else if(num[j]==1){
            char t='a'+j;
            temp.push_back(t);
        }
    }
    return temp;

}
int main(){
    string str;
    cout<<"Enter your string"<<" ";
    getline(cin,str);
    cout<<compress(str);
    

}