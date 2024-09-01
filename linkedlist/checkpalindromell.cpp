#include<iostream>
#include<vector>
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

//optimised
// Getting mid node
Node* getmid(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;     
}
// reversing the linked list
Node* reverse(Node* head){
    Node* prev=NULL;
    Node* forward=NULL;
    Node* curr=head;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
bool checknew(Node* head){
    //Step1-> GetMid
    Node* mid=getmid(head);
    Node* temp=mid->next;
    //reverse the linkedlist after mid value
    mid->next=reverse(temp);
    Node* head2=mid->next;
    //Compare both halves of linkedlist
    while(head2!=NULL){
        if(head->data!=head2->data){
            return 0;
        } 
        head=head->next;
        head2=head2->next;     
    }
    return 1;
}

//unoptimised
bool check(vector<int> arr){
    int s=0;
    int n=arr.size();
    int e=n-1;
    while(s<e){
        if(arr[s]!=arr[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
vector<int> checkpalindrome(Node* head , Node* tail){
    Node* temp=head;
    vector<int> nodes;
    while(temp!=NULL){
        nodes.push_back(temp->data);
        temp=temp->next;
    }
    return nodes;
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
    insertattail(tail,13);
    insertattail(tail,1);
    insertattail(tail,13);
    insertattail(tail,10);
    print(head);
    // bool soln1=check(checkpalindrome(head,tail));
    // if(soln1){
    //     cout<<"It is palindrome"<<endl;
    // }  
    // else{
    //     cout<<"It is not palindrome"<<endl;
    // } 
    bool soln2=checknew(head);
    if(soln2){
        cout<<"It is palindrome"<<endl;
    }  
    else{
        cout<<"It is not palindrome"<<endl;
    } 
}

