#include <bits/stdc++.h> 
#include<algorithm>
using namespace std;
class NStack
{
public:
    // Initialize your data structure.
    int* arr;  //arr to store your stack
    int* top;  // arr to store the position of each stack is using Ex: 3stack given top=[-1,-1,-1], if top=[0,3,-1] i.e stack1 has used  0index in array and stack2 has use 1,2,3 index of arrays and stack3 hsa not been used
    int* next; // gives you the next index in array which is free to use/(insert)
    int n,s;
    int freespot; //to keep a point on which index in array is free
    NStack(int N, int S)
    {
        // Write your code here.
        n=N;
        s=S;
        arr=new int[s];
        top=new int[n];
        next=new int[s];
        //initializing top with -1
        for(int i=0;i<n;i++){
            top[i]=-1;
        }
        //initializing next next free indexes of array
        for(int i=0;i<s;i++){
            next[i]=i+1;
        }
        //update last index val to -1
        next[s-1]=-1;

        //initialiase free spot i.e first freespot in arr is always in index 0
        freespot=0; 

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
    
        //check for overflow if array is filled 
        if(freespot==-1){
            return false;
        }
        //find index to insert the  elem in array
        int index=freespot;

        //update freespot gives you the index of array from next array which is empty
        freespot=next[index];

        //insert element in array
        arr[index]=x;

        // update next , in push we update next array in such a way that we keep filling it with index of array of prev elem of a stack to pop
        next[index]=top[m-1];

        // update top , as we push in stack it updates the index which is being used by the stack,if top=[0,3,-1] i.e stack1 has used  0index in array and stack2 has use 1,2,3 index of arrays and stack3 hsa not been used
        top[m-1]=index;

        return true;


    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        
        // check underflow if a stack is already empty
        if(top[m-1]==-1){
            return -1;
        }

        int index=top[m-1];  // gets the index of array from top to pop a element from stack

        top[m-1]=next[index]; // next[index] gives the index of array where prev elem of stack is kept

        next[index]=freespot;  // in pop, next is updated in such a way as element is being popped index of empty posn of array is updated from freespot

        freespot=index;

        return arr[index];

    }
    int peek(int m){
        if(top[m-1]==-1){
            return -1;
        }
        else{
            return arr[top[m-1]];
        }        
    }

    bool empty(int m){
        if(top[m-1]==-1){
            return true;
        }
        else{
            return false;
        } 

    }
    
};

int main(){
    NStack s(3,6);
    s.push(1, 1);
    s.push(2,1);
    s.push(5,1);
    s.push(9,2);
    while(!s.empty(1)){
        cout<<s.pop(1)<<" "<<endl;
        
    }
}