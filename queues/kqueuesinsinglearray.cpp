#include<iostream>
#include<vector>
using namespace std;
class kqueue{
    public:
    int* arr;  //array to store queues
    int* next;  //next array to store the next free index
    int* front; //to store the position of index of array from where to pop for all queues Ex:u have 3 queues,front=[0,3,-1]for 1st queue u need to pop from arr[0], for2nd arr[3],3rd queue is empty
    int* rear;  //to store the position of index of array where the current/last ele of queue is present Ex=rear[1,5,-1],for 1st queue its last ele is present at arr[1],for 2nd queue its last ele is present at arr[5],no ele is pushed in 3rd queue
    int freespot;//gives the index of next freespot starts with 0
    int s,n;

    kqueue(int S,int N){
        this->s=S;
        this->n=N;
        arr=new int[s];
        next=new int[s];
        front=new int[n];  
        rear=new int[n];      
        freespot=0;
        for(int i=0;i<s;i++){
            next[i]=i+1;
        }
        next[s-1]=-1;
        for(int i=0;i<n;i++){
            front[i]=-1;
            rear[i]=-1;
        }
    }
    void push(int x, int M){
        if(freespot==-1){ //if freespot reaches last posn of array i.e index==s
            cout<<"Queue is full"<<endl;
        }
        int index=freespot;
        freespot=next[index]; //take the next freespot from next array
        if(front[M-1]==-1){  //if a queue is empty
            front[M-1]=index; // set front of that queue = position of arr where its first element is being inserted(only for first element  of queue)
        }
        else{
            next[rear[M-1]]=index; // inpush we update next for storing the next index of array which is to be poped,when popping a ele user will get its index from front(arr) but then front will be updated using next.Ex[1,3,-1,-1,-1],say front=[0,2,-1],for 1st queue after popping from arr[0],front[1,2,-1],2nd ele will be popped from arr[1],then front[3,2,-1],3rd ele will be popped from arr[3];then front=[-1,2,-1],1st queue is empty
        }
        next[index]=-1;// after a freespot has been taken set its next[index]=-1
        rear[M-1]=index; //update rear to the posn of arr its being pushed.
        arr[index]=x;
    }
    int pop(int M){
        //Underflow Condition
        if(front[M-1]==-1){ 
            cout<<"Queue is empty"<<endl;
            return -1;
        }        
        int index=front[M-1]; //to pop the element from a certain index for a queue, take that index from the front arr
        front[M-1]=next[index]; //beacuse a element is going to be popped, we need to update the index in front so to get the index of next ele to be popped,you can get it from next[front[m-1]]
        next[index]=freespot; //after a ele is being popped from a certain index is getting freed to set the freespot to that free index, we need to connect the old freespot to new freespot which just got freed;
        freespot=index;  //setting freespot to new freed index.
        return arr[index];
    }
};
int main(){
    kqueue q(5,3);
    q.push(1,1);
    q.push(2,1);
    q.push(3,2);
    q.push(4,1);
    cout<<q.pop(1)<<endl;
    cout<<q.pop(2)<<endl;
    cout<<q.pop(1)<<endl;
    cout<<q.pop(1)<<endl;
}