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
Node* reverse(Node *head){
    Node* prev=NULL;
    Node* current=head;
    Node* forward=NULL;
    while(current!=NULL){
        forward=current->next;
        current->next=prev;
        prev=current;
        current=forward;        
    }
    return prev;
}
//Method1 start here
void insertattailforadd(Node*&head,Node*&tail,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
    return;
}
Node* sumll(Node* inp1,Node* inp2){
    Node* anshead=NULL;
    Node* anstail=NULL;

    int val=0;
    int carry=0;
    while(inp1!=NULL && inp2!=NULL ){
        int digit=carry+inp1->data+inp2->data;
        val=(digit)%10;
        insertattailforadd(anshead,anstail,val);
        carry=digit/10;
        inp1=inp1->next;
        inp2=inp2->next;
    }
    while(inp1!=NULL ){
        int digit =(carry+inp1->data);
        val=(digit)%10;
        insertattailforadd(anshead,anstail,val);
        carry=digit/10;
        inp1=inp1->next;
    }
    while( inp2!=NULL ){
        int digit=(carry+inp2->data);
        val=(digit)%10;
        insertattailforadd(anshead,anstail,val);
        carry=digit/10;
        inp2=inp2->next;
    }
    while(carry!=0 ){
        val=carry;
        insertattailforadd(anshead,anstail,val);
    }
    return anshead;
}
Node* addtwoll(Node* first, Node* second){
    //Step1->reversing ll
    first=reverse(first);
    second=reverse(second);

    Node* ans=sumll(first,second);
    ans=reverse(ans);
    return ans;

}
// Method1 end here

//Method2 starts here
Node* add(Node* head1,Node* head2){
    //Step1->reversing the nodes so that not to keep a pointer in end of ll
    Node* headn1=reverse(head1);
    Node* headn2=reverse(head2);
    int val=0;
    //Step2 ->Creating a first node  so that next nodes can be attached at its end
    Node* newnode=new Node((headn1->data + headn2->data)%10);
    Node* start=newnode; // keeping a pointer in start so to reverse it later
    int carry=(headn1->data + headn2->data)/10;
    headn1=headn1->next;
    headn2=headn2->next;
    while(headn1!=NULL || headn2!=NULL){
        if(headn2==NULL && headn1!=NULL){
            val=headn1->data+carry;
        }
        if(headn1==NULL && headn2!=NULL){
            val=headn2->data+carry;
        } 
        if(headn1!=NULL && headn2!=NULL){ 
        val=headn1->data + headn2->data+carry;
        }
        carry=val/10;
        Node* nodes=new Node(val%10);
        newnode->next=nodes;
        newnode=nodes;
        if(headn1!=NULL){
            headn1=headn1->next;
        }
        if(headn2!=NULL){
            headn2=headn2->next;
        }
    }
    Node* head=reverse(start);
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
    Node*nani=new Node(2);
    Node* panyu=new Node(5);
    cout<< nani->data<<endl;
    cout<< nani->next<<endl;
    // head pointed to nani
    Node* headn=nani;
    // creating 2nd node which will become 1st 
    Node* tailn=nani;
    Node* headp=panyu;
    Node* tailp=panyu;
    // insertathead(head,13);
    // insertathead(head,15);
    // print(head);
    // inserting at tail
    insertattail(tailn,1);
    insertattail(tailn,5);
    insertattail(tailp,7);
    insertattail(tailp,9);
    // insertattail(tailp,9);
    print(headn);
    print(headp);
    Node* newll=addtwoll(headn,headp);
    print(newll);
}