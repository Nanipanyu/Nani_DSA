#include<iostream>
#include<algorithm>
using namespace std;
string remove(string s){
    string temp;
    temp.push_back(s[0]);
    int i=1;
    while(i<s.length()){


        if(s[i]==temp[temp.length()-1] ){
            temp.pop_back();
            
        }
        else{
            temp.push_back(s[i]);
        }
        i++;
    }
    return temp;
}
int main(){
    string str;
    cout<<"Enter your string"<<" ";
    getline(cin,str);
    cout<<remove(str);
}