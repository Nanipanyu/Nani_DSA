#include<iostream>
using namespace std;

class stack{
    public:
        int top;
        int* arr;
        int size;

    stack(int size){
        this->size=size;
        arr=new int[size];
        this->top=-1;
    }
    void push(int n){
        if(top<size-1){
            arr[++top]=n;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            top--;
        }
    }
    int peek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    stack s(2);
    s.push(10);
    s.push(5);
    s.push(21);
    cout<<"peeked"<<s.peek()<<endl;
    s.pop();
    while(!s.isempty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
}