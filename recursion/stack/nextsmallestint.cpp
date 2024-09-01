#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//1st solution(not optimal)
int insert(stack<int> &s,int num){
    // Unless the top element of stack is smaller pop the top element  
    while(!s.empty() && s.top()>=num){
        s.pop();        
    }
    // ans is stack ka top replace the vector val with this val
    int top=s.top();
    s.push(num);
    return top;
}
vector<int> nextSmallerElement1(vector<int> &arr, int n)
{
    // Write your code here.
    n--;
    stack<int> st;
    //intitializing stack with -1;
    st.push(-1);
    while(n>=0){
        int temp=arr[n]; //taking the val of vector
        int next=insert(st,temp);
        arr[n]=next;
        n--;                      
    }
    return arr;
}

//Second solution (OPtimal)
vector<int> nextSmallerElement2(vector<int> &arr, int n)
{
    stack<int> st;
    //intitializing stack with -1;
    st.push(-1);
    vector<int> result(n);
    n--;
    
    while(n>=0){
        //keep popping  until samller element is found in stack
        while(st.top()>=arr[n]) {
            st.pop();
        } 
        //after you got the next smaller element assign the smaller value and insert the prev val in stack 
        result[n]=st.top();
        st.push(arr[n]);  
        n--;                 
    }
    return result;
}

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(1);
    v.push_back(3);
    vector<int> m=nextSmallerElement2(v,4);
    for(int i=0;i<m.size();i++){
        cout<<m[i]<<" ";
        }

}