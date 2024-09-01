#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
};
// traversing a linked list
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertathead(Node* &head,Node* &tail,int data){
    // if empty Node
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp=new Node(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void insertattail(Node* &tail,Node* &head,int data){
    // if empty Node
    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        head=temp;
    }
    else{
        Node* temp=new Node(data);
        temp->prev=tail->next;
        tail->next=temp;
        tail=temp;
    }    
}
int getlength(Node* &head){
    int count=1;
    Node* temp=head;
    while(head->next!=NULL){
        count++;
        head=head->next;
    }
    // pointing head back to start
    head=temp;
    return count;
}
void insertatposn(Node* &tail,Node* &head,int data,int posn){
    // inserting at start
    if(posn==1){
        insertathead(head,tail,data);
        return;
    }
    // inserting at middle    
    int cnt=1;
    Node* temp=new Node(data);
    Node* curr=head;
    Node* before=NULL;
    while(cnt<posn && curr!=NULL){
       
        before=curr;
        curr=curr->next;           
        cnt++;
    }  
    // inserting at end
    if(before->next==NULL){
        insertattail(tail,head,data);
        return;
    }
    temp->prev=before;
    temp->next=curr;
    before->next=temp;
    curr->prev=temp;

}

int main(){
    // Node* node1=new Node(10);
    Node*head = NULL;
    Node*tail = NULL;
    print(head);
    insertathead(head,tail,9);
    insertathead(head,tail,8);
    insertattail(tail,head,11);
    insertattail(tail,head,12);
    print(head);
    insertatposn(tail,head,7,5);
    print(head); 
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
}