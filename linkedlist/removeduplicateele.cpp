#include<iostream>
#include<map>
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
void insertnode(Node* &tail,Node* &head,int d,int n){
    Node* mid=new Node(d);
    Node* temp=head;
    int i=1;
    // insert at starting posn
    if(n==1){
        mid->next=temp;
        head=mid;
    }
    // insert at mid posn 
    else{
        while(temp!=NULL && i<n ){
            if(i==n-1){
            // Node *tempc=temp;
                mid->next=temp->next;
                temp->next=mid;
            }
            i++;
            temp=temp->next;
        }
    }
    if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }
}
void insertathead(Node* &head,int d){
    Node* temp=new Node(d);
    // assigning previous node address in it
    temp->next=head;
    head=temp;
}

void deletenode(int posn,Node* &head,Node* &tail){
    
    // if 1st node is to be deleted
    if(posn==1){
        Node* dup=head;
        head=head->next;
        dup->next=NULL;
        delete dup;
    }
    // deleting any middle node or last node
    else{
        Node* current=head;
        Node*temp=NULL;
        int i=1;
        while(i<posn){
            i++;
            temp=current;
            current=current->next;                
        }
        temp->next=current->next;
        // when deleting last  node taking care of tail to be in last node
        if(temp->next==NULL){
            tail=temp;
        }
        // mmemory freed
        current->next=NULL;
        delete current; 
    }
}
//only works for sorted list
void removesorted(Node* head){
    if(head==NULL){
        return;
    }
    Node* curr=head;
    while(curr->next!=NULL){
        if(curr->data!=curr->next->data){ //check if the next value is same if not move curr forward
            curr=curr->next;
        }
        else{  //if he next value is same then point curr to its next to next value and delete next
            Node* Next=curr->next;
            curr->next=Next->next;
            Next->next=NULL;
            delete Next;
            }
        }
        return;
    }
void removeunsorted(Node* head){
    Node* curr=head;
    Node* check=curr;
    while(curr!=NULL && curr->next!=NULL){
        check=curr;
        while(check->next!=NULL){
            if(check->next->data!=curr->data){ //check if the next value is same if not move curr forward
            check=check->next;
        }
            else{  //if he next value is same then point curr to its next to next value and delete next
                Node* todelete=check->next;
                check->next=todelete->next;
                todelete->next=NULL;
                delete todelete;
            }    
        }
        curr=curr->next;
    }
}
void removeunsortedmap(Node* head){ //using map to delte duplicates
    map<int, bool> visited; // map stores data in pair of key and value
    Node* temp=head;
    Node*prev=NULL;
    Node* forward=head;
    while(temp!=NULL){ //while traversing through each unique pair in loop mark its bool true
        if(visited[temp->data]==true){ //if it is already visited then its bool value will be 1 means it has a loop
            prev->next=temp->next;
            forward=temp->next;
            temp->next=NULL;
            delete temp;
            temp=forward;
            }
        
        else{
            visited[temp->data]=true;
            prev=temp;
            temp=temp->next;
            forward=temp;
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
    // creating 2nd node which will become 1st 
    Node* tail=nani;
    // insertathead(head,13);
    // insertathead(head,15);
    // print(head);
    // inserting at tail
    insertattail(tail,10);
    insertattail(tail,15);
    insertattail(tail,22);
    insertattail(tail,27);
    print(head);
    removesorted(head);
    cout<<"aftersorted remove-"<<" ";
    print(head);
    insertattail(tail,10);
    // removeunsorted(head);
    // print(head);
    // cout<<tail->data;
    insertnode(tail,head,10,2);
    insertnode(tail,head,27,6);
    print(head);
    removeunsorted(head);    
    removeunsortedmap(head);
    print(head);
}