#include <iostream>
#include<algorithm>
#include <climits>
using namespace std;

class SpecialStack {
    public:
    int *arr;
    int *minn; //array to store the min value of stackin each stage
    int ind; 
    int size;

    SpecialStack(int s){
        this->size=s;
        arr=new int[size];
        minn=new int[size];
        this->ind=-1;
    } 
    void push(int data) {
    if (ind < size - 1) {
        arr[++ind] = data;
        // while u push elem in actual stack keep Updating the minimum value of stack in minn array if new push elem is smaller than the previous samllest stack element by comparing it with the rest values of stack in bottom
        if (ind == 0) {
            minn[ind] = data; // First element
        } else {
            minn[ind] = min(minn[ind - 1], data); // Update minimum
        }
    } else {
        cout << "Stack overflow" << endl;
    }
}
          


    void pop() {
        // Implement the pop() function.
        if(ind==-1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            ind--;
        }
    }

    int top() {
        // Implement the top() function.
        if(ind==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else{
            return arr[ind];
        }
    }

    int getMin() {
        // Implement the getMin() function.
        if(ind==-1){
            return -1;
        } else {
            //return the min val of  stack 
            return minn[ind];
        }
    }  
};

int main(){
    SpecialStack s(3);
    s.push(5);
    s.push(2);
    s.push(8);
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.getMin()<<endl;
}