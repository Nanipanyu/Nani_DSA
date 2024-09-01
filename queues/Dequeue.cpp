#include <bits/stdc++.h> 
using namespace std;
class Deque
{
public:
    // Initialize your data structure.
    int *arr;
    int front;
    int rear;
    int size;
    Deque(int n)
    {
        // Write your code here.
        this->size=n;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    
    bool pushFront(int x)
{
    if((rear==size-1 && front==0)  || (rear==front-1)) {
        return false;  // The deque is full check
    }

    // If deque is empty
    if(front == -1) {
        front = 0;
        rear = 0;
    }
    else if(front == 0) {
        front = size - 1;  // Wrap around to the end of the array
    }
    else {
        front--;  // Move front backward to push next element in front of dequeue
    }

    arr[front] = x;
    return true;
}

bool pushRear(int x)
{
    if((rear==size-1 && front==0)  || (rear==front-1)) {
        return false;  // The deque is full check
    }

    // If deque is empty( to start)
    if(front == -1) {
        front = 0;
        rear = 0;
    }
    else if(rear == size - 1) {
        rear = 0;  // Wrap around to the start of the array
    }
    else {
        rear++;  // Move rear forward to push next element in rear of dequue
    }

    arr[rear] = x;
    return true;
}


    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(rear==-1  && front==-1){ //emtpy check
            return -1;
        }
          
        int data=arr[front];

        if(front == rear){  //while poping if it gets empty set front and rear =-1
            // int data= front;
            front= -1;
            rear=-1;
        } 
        else if(front==size-1 ){ //wrap around to start of array
            front=0;
        }     
        else {
            front++;
        }        
        return data;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(rear==-1 && front==-1){ //empty check
            return -1;
        }
        // else if(rear==-1 && front!=-1){
        //     rear = size-1;
        // }
          
        int data=arr[rear];

        if(front == rear){ //while poping if it gets empty set front and rear =-1
            front= -1;
            rear=-1;
        }  
        else if(rear == 0) { //wrap around to start from end of array
            rear=size-1;
        }    
        else {
            rear--;
        }        
        return data;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty()){ //empty check
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front==-1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((rear==front-1) || (rear==size-1 && front==0)){
            return true;
        }
        else{
            return false;
        }
    }
};