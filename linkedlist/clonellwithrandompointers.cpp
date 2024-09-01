#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;
    // constructor called
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->random=NULL;
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
    // creating 2nd node which will become 1st 
    Node* tail=nani;
    insertattail(tail,13);
    insertattail(tail,15);
    insertattail(tail,17);
    insertattail(tail,22);
    print(head);

}

//Its hard to generate randompointers here so if you want to revise go and check lecture 52 luv babbar DSA

