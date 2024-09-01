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
void insertatmiddle(Node* &tail,Node* &head,int d,int n){
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
void sortlinks(Node* &head){  //sorting by changing the links among the nodes, we seperate the 0,1,2 in different ll and join them; if data replacement is not allowed
    Node* temp=head;
    Node* zero=NULL; 
    Node* one=NULL;
    Node* two=NULL;
    Node* onehead=NULL; //to keep a head at 1,s ll
    Node* twohead=NULL; //to keep a head at 2,s ll    
    while(temp!=NULL){
        if(temp->data==0){
            if(zero==NULL){  //if first zero is found start the seperate zero,s ll
                zero=temp;
                head=zero; // assign the final head at beginning of 0 ll;
            }
            else{
                zero->next=temp;  //if zero is found keep stacking in the zero,s ll
                zero=zero->next;
            }                
        }
        if(temp->data==1){   //if first one is found start the seperate one,s ll
            if(one==NULL){
                one=temp;
                onehead=one;                
            }
            else{
            one->next=temp;   //if one is found keep stacking in the one,s ll
            one=one->next;
            }             
        }
        if(temp->data==2){    //if first two is found start the seperate two,s ll
            if(two==NULL){
                two=temp;
                twohead=two;                
            }
            else{             //if two is found keep stacking in the two,s ll
            two->next=temp;
            two=two->next; 
            }             
        }
        temp=temp->next;
    }
    // connecting the linkedlist
    zero->next=onehead;   
    one->next=twohead;
    two->next=NULL;
}
void sort(Node* head){  //sorting by calculating the numbers of 0,1,2 adn then traversing the ll and changing their values
    Node* temp=head;
    int zerocnt=0;
    int onecnt=0;
    int twocnt=0;
    while(head!=NULL){
        if(head->data==0){
           zerocnt++; 
        }
        if(head->data==1){
           onecnt++; 
        }
        if(head->data==2){
           twocnt++; 
        }
        head=head->next;
    }
    int i=0;
    while(i<zerocnt){
        temp->data=0;
        temp=temp->next;
        i++;
    }
    i=0;
    while(i<onecnt){
        temp->data=1;
        temp=temp->next;
        i++;
    }
    i=0;
     while(i<twocnt){
        temp->data=2;
        temp=temp->next;
        i++;
    }    
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    // creating first node 
    Node*nani=new Node(0);
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
    insertattail(tail,2);
    insertattail(tail,2);
    insertattail(tail,0);
    insertattail(tail,1);
    print(head);
    insertatmiddle(tail,head,1,5);
    print(head);
    // sort(head);
    // print(head);
    sortlinks(head);
    print(head);
}