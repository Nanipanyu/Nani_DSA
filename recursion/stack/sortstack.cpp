#include<iostream>
#include<stack>
using namespace std;
// function for inserting a element sorted
void insertsorted(stack<int>&s,int x){
    // base case
    if(s.empty() || x>s.top()){
        // when bottom reached insert the element or if x(element to be inserted) is greater the the element at top of stack(so it is sorted)
        s.push(x);
        return;
    }
    // else remove the elements greater than x , so to insert x sorted
    int num=s.top();
    s.pop();
    insertsorted(s,x);
    s.push(num);
}

void sortStack(stack<int> &stack) {
    // Base case
    if(stack.empty()){
        return;
    }
    //poping out top element and sending the stack recursively
    int num=stack.top();
    stack.pop();
    sortStack(stack);
    // while putting back the values in stack putting it sorted
    insertsorted(stack,num);
}

int main(){
    stack<int> s;
    s.push(8);
    s.push(2);
    s.push(9);
    s.push(0);
    s.push(5);
    sortStack(s);    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}