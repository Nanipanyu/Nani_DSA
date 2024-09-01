#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
class CircularQueue{    
    public:
    // Initialize your data structure.
    int *arr;
    int front;
    int rear;
    int size;
    CircularQueue(int n){
        // Write your code here.
        this->size=n;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.        
        if(rear==size-1 && front>-1){  //wrapping around circularly
            rear=0;            
        }
        else if((rear==size-1 && front==0)  || (rear==front-1)){  //full check
            return false;
        }
        else{        //othercases increases rear to insert value
            rear++; 
            //  rear<size  || rear==front &&    if(rear!=front || (rear==front && front==0))       
        }
        arr[rear]=value;
        return true ;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(rear==-1){    //empty check
            return -1;
        }
        else if(front==size || front==-1){  //wrap around check and if first deque
            front=0;
        }   
        int data=arr[front];  //storing val to deque ,because we need to update the front for next step

        if(front == rear){    //if 1 element then queue is goona be empty after dequing so set the front and rear to =-1
            int data= front;
            front= -1;
            rear=-1;
        }     
        else if(front!=rear ){  //keep increasing front to deque
            front++;
        }        
        return data; //return the deque element

    }
};