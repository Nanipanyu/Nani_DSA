#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next=NULL;
    Node(int data){
        this->data=data;
    }
};
void insertattail(int d,Node* &tail){
    Node *temp=new Node(d);
    if(tail==NULL){
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    } 
}
// void reverse(Node* &head,Node* &tail){
//     Node* forward=NULL;  
//     Node* prev=NULL;
//     Node* curr=head;
//     while(curr!=NULL){
//         forward=curr->next; //to have access to the remaining pointer while curr->next points to prev
//         curr->next=prev;
//         prev=curr;
//         curr=forward;
//     }
//     tail=head;
//     head=prev;  
// }
void reverse(Node* &head, Node* prev, Node* curr){
    if(curr==NULL){
        head=prev;
        return;
    }
    Node *forward=curr->next;
    reverse(head,curr,forward );
    curr->next=prev;
}

void print(Node* head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;    

}

int main(){
    Node *node1=new Node(10);
    Node *temp=node1;
    Node *head=node1;
    Node *tail=node1;
    insertattail(20,tail);
    insertattail(30,tail);
    insertattail(40,tail);
    print(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;
    Node*prev=NULL;
    reverse(head,prev,head);
    print(head);
    cout<<head->data;
}