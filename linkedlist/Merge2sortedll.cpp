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
Node* merge(Node* head1,Node* tail1,Node* head2,Node* tail2){
    if(head1==NULL ){
        return head2;
    }
    if(head2==NULL ){
        return head1;
    }

    if(tail1->data<=head2->data){
        tail1->next=head2;
        return head1;
    }
    if(tail2->data<=head1->data){
        tail2->next=head1;
        return head2;
    }
    if(head1->data<=head2->data){ //which ll first val is smaller keep it in nested loop,and keep on checking with each value of other ll 
        Node* curr=head1;
        Node* prev=NULL;
        Node* temp2=head2; //head pointer stored to run the smaller ll again from starting in nested loop
        while(curr!=NULL){
            while(head2!=NULL){
                if(head2->data<curr->data){  //if head2 ll val is smaller then to insert in the head1 ll
                    // cout<<"i reached"<<endl;
                    Node* temp=head2->next; //track pointer to keep a track of head2 ll after inserting a value of head2 in head1ll
                    head2->next=curr;  //inserting between curr and prev
                    prev->next=head2;
                    prev=head2; //pointing prev to the inserted value
                    head2=temp; 
                    temp2=temp; //since a node of head2ll is inserted in head1ll head2 loop has to start from the next node so updating it                   
                }
                else{
                    head2=head2->next; //update head2 only if it bigger and not inserted in head1 otherwise it is being already updated in if condn 
                }                
            }
            head2=temp2; //initialising head2 with the next node of the one been taken
            prev=curr;
            curr=curr->next;
        }
        tail1->next=head2;
        return head1;
        }
    else{
        Node* prev=NULL;
        Node* curr=head2;
        Node* temp1=head1;
        while(curr!=NULL){
            while(head1!=NULL){
                if(head1->data<curr->data){
                    Node* temp=head1->next;
                    head1->next=curr;
                    prev->next=head1;
                    prev=head1;
                    head1=temp;
                    temp1=temp;               
                }
                else{
                    head1=head1->next;
                }                
            }
            head1=temp1;
            prev=curr;
            curr=curr->next;
        }
        return head2;
    }
        
}
Node* mergeoptimised(Node* head1,Node* tail1,Node* head2,Node* tail2){  //better solution
     if(head1==NULL ){
        return head2;
    }
    if(head2==NULL ){
        return head1;
    }

    if(tail1->data<=head2->data){
        tail1->next=head2;
        return head1;
    }
    if(tail2->data<=head1->data){
        tail2->next=head1;
        return head2;
    }
    Node* mergehead=NULL;
    Node* mergetail=NULL;
    if(head1->data<=head2->data){
        mergehead=head1;
        head1=head1->next;
    }
    else{
        mergehead=head2;
        head2=head2->next;
    }
    mergetail=mergehead;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            mergetail->next=head1;
            head1=head1->next;
        }
        else{
            mergetail->next=head2;
            head2=head2->next;
        }
        mergetail=mergetail->next;
    }
    if (head1 != NULL) {
        mergetail->next = head1;
    } else {
        mergetail->next = head2;
    }
    return mergehead;
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
    Node*nani=new Node(2);
    Node*panyu=new Node(1);
    cout<< nani->data<<endl;
    cout<< nani->next<<endl;
    // head pointed to nani
    Node* head1=nani;
    Node* tail1=nani;
    Node* head2=panyu;
    Node* tail2=panyu;
    // creating 2nd node which will become 1st 
    // insertathead(head,13);
    // insertathead(head,15);
    // print(head);
    // inserting at tail
    insertattail(tail1,3);
    insertattail(tail1,5);
    insertattail(tail2,2);
    insertattail(tail2,7);
    print(head1);
    // insertatmiddle(tail,head,1,5);
    print(head2);
    // deletenode(6,head,tail);
    // cout<<tail1->data<<endl;
    Node* val=mergeoptimised(head1,tail1,head2,tail2);
    // cout<<val->data<<endl;
    print(val);
}