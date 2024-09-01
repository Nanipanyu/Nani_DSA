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
bool loopcheck(Node* head){
    if(head==NULL){
        return false;
    }
    map<Node*, bool> visited; // map stores data in pair of key and value
    Node* temp=head;
    while(temp!=NULL){ //while traversing through each unique pair in loop mark its bool true
        if(visited[temp]==true){ //if it is already visited then its bool value will be 1 means it has a loop
            cout<<"present on element"<<temp->data<<endl;
            return 1;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
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
    tail->next=head->next;
    if(loopcheck(head)){
        cout<<"loop is there"<<endl;
    }
    else{
        cout<<"Noloop"<<endl;
    }
   
}