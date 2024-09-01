#include<iostream>
#include<stack>
using namespace std;
// function for inserting a element at bottom of stack
void insertatbottom(stack<int>&s,int x){
    // base case
    if(s.empty()){
        // when bottom reached insert the element
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    insertatbottom(s,x);
    s.push(num);
}

void reverseStack(stack<int> &stack) {
    // Base case
    if(stack.empty()){
        return;
    }
    //poping out top element and sending the stack recursively
    int num=stack.top();
    stack.pop();
    reverseStack(stack);
    // while putting back the values in stack putting it at the bottom
    insertatbottom(stack,num);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverseStack(s);    
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

}