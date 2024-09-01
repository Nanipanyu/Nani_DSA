#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string rev(string g){
    int s=0;
    int e=g.length()-1;
    while(s<e){
        swap(g[s],g[e]);
        s++;
        e--;
    }
    return g;
}
bool search(string s,string d ){
    // while(s.length()!=0 && s.find(d)<s.length()){
    
       if(s.find(d)<s.length()){
        return 1;
       }
       else if(s.find(rev(d))<s.length()){
        return 1;
       }
       
       else{
        return 0;
       }


    }
    



int main(){
    string str;
    string st;
    cout<<"enter your string"<<" ";

    getline(cin,str);
    cout<<"enter your substring"<<" ";

    getline(cin,st);

    cout<<search(str,st);
}


