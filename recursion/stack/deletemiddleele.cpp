#include<iostream>
#include<stack>
using namespace std;

// Recursive solution
void solve(stack<int>&input,int count ,int size){ //In C++ stack is default passed by value so you need to pass it as reference
    // base case
    if(count==size/2){
        input.pop();
        return;
    }
    int num=input.top();
    input.pop();
    solve(input,count+1,size);
    input.push(num);
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    //Getting length of stack to get the mid and remove it
    int length=s.size();

    //creating a temp stack to store the value from original stack while we pop it to remove the mid value
    stack<int> temp;
    
    for(int i=0;i<(length/2)+1;i++){
        temp.push(s.top());
        s.pop();
    }
    temp.pop();//removing the mid val
    length=temp.size();

    // pushing the above mid data back to original stack 
    for(int i=0;i<length;i++){
        s.push(temp.top());
        temp.pop();
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    // using recursion
    stack<int>n;
    n.push(1);
    n.push(2);
    n.push(3);
    n.push(4);
    n.push(5);
    int count=0;
    int newlength=n.size();
    solve(n,count,newlength);
    while(!n.empty()){
        cout<<n.top()<<" ";
        n.pop();
    }
}