#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
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
void insertnode(Node* &tail,int val,int d){
    // if empty node 
    if(tail==NULL){
        Node* temp = new Node(d);
        temp->next=temp;
        tail = temp;
    }
    else{
        Node* temp = tail;
        // traversing to find the node having value val
        while(temp->data!=val){
            temp = temp->next;
        }

        if(temp==tail && temp->next==NULL){  //if there is a single node then first make it circular  otherwise you have to start with tail=NULL(empty node)
            temp->next=temp;
        }
        Node* insertval = new Node(d);
        insertval->next=temp->next;
        temp->next=insertval;
    }
}
void deletenode(Node* &tail,int val){
    Node *prev=tail;
    Node* curr=prev->next;
    if(curr==prev){  //1 node linked list
        tail==NULL;
    }
    while(curr->data!=val){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    curr->next=NULL;
    if(curr==tail){   //if first node is deleted than point tail to next node for>=2 node ll
        tail=prev->next;
    }
    delete curr;
}
void print(Node* tail){
    if (tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = tail; 
    do { //do is essential for only one node case
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}


int main(){
    Node* node1 =new Node(10);
    Node* tail=node1;
    insertnode(tail,10,20);
    print(tail);
    Node* nxt=tail->next;
    // check if it is circular(start)
    cout<<"tail is"<<" "<<tail<<endl;
    cout<<"check"<<" "<<nxt->next<<endl;
    // end
    insertnode(tail,20,21);
    insertnode(tail,21,22);
    insertnode(tail,10,15);
    insertnode(tail,15,25);
    print(tail);
    deletenode(tail,25);
    print(tail);
    deletenode(tail,22);
    print(tail);
    deletenode(tail,10);
    print(tail);
    deletenode(tail,15);
    print(tail);
    deletenode(tail,20);
    print(tail);
    deletenode(tail,21);
    print(tail);
}
