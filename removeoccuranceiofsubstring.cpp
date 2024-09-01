#include<iostream>
using namespace std;
string remove(string s,string d){
    while(s.length()!=0 && s.find(d)<s.length() ){
        s.erase(s.find(d),d.length());
    }
    return s;
  

}
int main(){
    string s;
    string d;
    cout<<"Enter your sentence"<<" ";
    getline(cin,s);
    cout<<"Enter your substring"<<" ";
    getline(cin,d);
    cout<<"modified str"<<remove(s,d);



}