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
void breakloop(Node* head){
    if(head==NULL){
        return;     
    }
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && slow!=NULL){ //in floyd detection algorithm when both slow and fast enters loop with every iteration distance between them decreases by 1 step
        slow=slow->next;
        fast=fast->next->next;       
        if(fast==slow){
            slow=head;  //assigning slow to head so we can get a condition to stop our loop i.e until fast==slow and get the first node
             
            while(slow->next!=fast->next){ //to point the prev node of intersection node to NULL to break the loop
                fast=fast->next;
                slow=slow->next;    
            } 
            fast->next=NULL;  
            return;        
        }
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
    insertattail(tail,17);
    print(head);   
    tail->next=head->next->next;
    // print(head);
    breakloop(head);
    print(head); 
    cout<<tail->data<<endl;
    cout<<tail->next<<endl; //check
}   