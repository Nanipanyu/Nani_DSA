#include<iostream>
#include<queue>
using namespace std;

//Node structure of linked list
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


class compare{  //to create a min heap(which stores node) such that its sorted based on node-> data
    public:
        bool operator()(Node* a,Node* b){
            return a->data > b->data;  // bigger ele will come after smaller ele ,i.e smaller ele will be at .top posn
        }
};

//merging k sorted linked list in sorted order and returning the final head (vector<Node*> &listArray  contains the head of k linkedlist)
Node* mergeKLists(vector<Node*> &listArray){
    //creating min heap 
    priority_queue<Node*,vector<Node*>,compare> mini;

    int k=listArray.size();
    Node *head=NULL;
    Node *tail=NULL;

    //insert head of all k linked list in minheap (s.t head with smallest val will be on top);  
    for(int i=0;i<k;i++){
        mini.push(listArray[i]);
    }

    while(mini.size()>0){  //until minheap is not empty keep attaching the linked list node in sorted order using minheap

        //stores the next smallest value
        Node* tmp=mini.top();

        //if head has not been created assign head and tail to the smallest head among k linked list
        if(head==NULL){
            head=tmp;
            tail=head;
        }
        else{  //attached the  smallest element among all the linkedlist to tail with help of minheap
            tail->next=tmp;
            tail=tail->next;
        }
        mini.pop(); //popping the smallest ele of mini

        if(tmp->next != NULL){  //if there are nodes present for linked list whose node has just been attached to tail(or node which has been popped from mini)
            Node* nxt=tmp->next; 
            mini.push(nxt); // insert its next node to mini
        }
        
    }
    return head;
}


