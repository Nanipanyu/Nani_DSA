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
int getlength(Node* head){
    int count=0;
    
    while(head!=NULL && head->next!=NULL){
        count++;    
        head=(head->next)->next; //To reach midway we can traverse the length by double jumping since in even cases the greater one is needed
    }
    return count;
}
void insertattail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
Node* getmiddle(Node* head){
    int cnt=0;
    int stop=getlength(head);
    while(cnt<stop){
        cnt++;
        head=head->next;
    }
    return head;
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
    Node* head=nani;
    // creating 2nd node which will become 1st 
    Node* tail=nani;   
    insertattail(tail,13);
    insertattail(tail,15);
    insertattail(tail,17);
    insertattail(tail,22);
    insertattail(tail,25);
    print(head);
    Node* middle=getmiddle(head);
    cout<<"mid val"<<" "<<middle->data<<endl;
}
