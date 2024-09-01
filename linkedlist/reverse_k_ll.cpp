#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    // constructor called
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next==NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"node of value is freed"<<value<<endl;
    }
};

void insertattail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

Node* reverse(Node* head, int k){
    // if empty list 
    if(head==NULL){
        return NULL;
    }
    int count=0;
    Node* prev=NULL;
    Node* curr=head;
    Node *forward=NULL;
    while(curr!=NULL && count<k){  //reversing till kth posn
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
    count++;
    }
    if(curr!=NULL){ //base case
        head->next=reverse(forward,k);  //attaching the rotated head with the remaining nodes after them  being rotated
    }
    return prev;   
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    // creating first node 
    Node*nani=new Node(10);
    cout<< nani->data<<endl;
    cout<< nani->next<<endl;
    // head pointed to nani
    Node* head=nani;
    Node* tail=nani;
    insertattail(tail,13);
    insertattail(tail,15);
    insertattail(tail,17);
    insertattail(tail,22);
    insertattail(tail,25);
    print(head);
    Node* f=reverse(head,3);
    cout<<f->data<<endl;
    print(f); 
}