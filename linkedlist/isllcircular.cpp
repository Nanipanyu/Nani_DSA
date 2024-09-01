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
void insertnode(Node* tail,int val,int d){
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
bool circularcheck(Node* head){
    if(head==NULL){
        return true;
    }
    Node* temp=head;
    do{
        head=head->next;
    } while(head!=temp && head!=NULL);
    if(head==temp){
        return true;
    }
    if(head==NULL){
        return false;
    }
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
    // insertattail(tail,17);
    // insertattail(tail,22);
    print(head);
    cout<<circularcheck(head)<<endl;
    insertnode(head,13,21);
    insertnode(head,21,22);
    insertnode(head,10,15);
    insertnode(head,15,25);
    print(head);  
    if(circularcheck(head)){
        cout<<"LL is circular"<<endl;
    }
    else{
        cout<<"ll is not circular"<<endl;
    }
    Node*n1=new Node(10);
    Node* h1=n1;
    insertnode(h1,10,12);
    insertnode(h1,12,14);
    if(circularcheck(h1)){
        cout<<"LL is circular"<<endl;
    }
    else{
        cout<<"ll is not circular"<<endl;
    }
}