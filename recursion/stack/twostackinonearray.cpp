#include <bits/stdc++.h> 
class TwoStack {

public:
    int* arr;
    int size;
    int top1;
    int top2;

    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        this->size=s;
        arr=new int[size];  
        top1=-1; //stack1 starting from left side of array
        top2=size;  //stack2 starting from right side of array    
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        
        if( top1<top2-1){
            arr[++top1]=num;
        }
        else{
            return;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        
        if( top2>top1+1 ){
            arr[--top2]=num;
        }
        else{
            return;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1==-1){
            return -1;
        }
        else{
            return arr[top1--];
            
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2==size){
            return -1;
        }
        else{
            return arr[top2++];
        }
    }
};
int main(){
    TwoStack s(5);
    s.push1(10);
    s.push1(5);
    s.push2(21);
    s.push2(27);
    // cout<<"peeked"<<s.peek()<<endl;
    s.pop1();
    // while(!s.isempty()){
    //     cout<<s.peek()<<" ";
    //     s.pop();
    // }
}