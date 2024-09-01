#include<iostream>
#include<queue>
using namespace std;
void reverse(queue<int> &q){ //recursion method
    if(q.empty()){
        return;
    }
    int ele=q.front();
    q.pop();
    reverse(q);
    q.push(ele);
}
  
queue<int> rev(queue<int> q)
{
        // add code here.
    reverse(q);
    return q;
}