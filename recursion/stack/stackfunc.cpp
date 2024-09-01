#include<iostream>
#include<stack>
using namespace std;
int main(){
    // creating stack
    stack<int> s;
    s.push(5);
    s.push(10);
    //pritning a stack
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    s.pop();
    cout<<"printing top element"<<s.top()<<endl;
    if(s.empty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    cout<<"size of stack is"<<" "<<s.size();
    return 0;
}