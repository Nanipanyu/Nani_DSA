#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
class Queue {
public:
    vector<int> arr;
    int fron; //index to remove elements form beginning
    int rear; //index to insert elements
    Queue() {
        // Implement the Constructor
        this->fron=0;
        this->rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(rear==0 || fron==rear){  //empty condition is only possible if rear=0(nothing inserted) or fron=rear(how much inserted that much taken out)
            return true;
        }
        else{
            return false;
        }

    }

    void push(int data) {
        // Implement the enqueue() function
        arr.push_back(data);
        rear++; //update rear to insert

    }

    int pop() {
        // Implement the dequeue() function
        if (rear != fron ) {  //condition for not empty queue
          int ans=arr[fron];
          fron++; //update fron to next element
          if(fron==rear){ //for space optimisiation if queue gets empty after pop then start filling again next time from start of array(if array is used it has benefits)
            fron=0;
            rear=0;
          }

          return ans;  //pop and move to next element from first

        }
        else{
            return -1;
        }
    }

    int front() {
        // Implement the front() function
        if (rear > 0 && fron!=rear) { //condition for not empty queue
            return arr[fron];
        }
        else{
            return -1;
        }
    }
};