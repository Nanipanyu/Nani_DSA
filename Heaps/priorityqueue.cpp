#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq; //maxheap
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(1);
    cout<<"ele at top"<<" "<<pq.top()<<endl;
    pq.pop(); //pops at the root node(i.e top node)
    cout<<"ele at top"<<" "<<pq.top()<<endl;
    cout<<"size is"<<" "<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"pq is empty"<<endl;
    }
    else{
        cout<<"pq is not empty"<<endl;
    }

    //min heap
    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(1);
    cout<<"ele at top"<<" "<<minheap.top()<<endl;

}
