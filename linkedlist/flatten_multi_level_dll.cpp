#include <iostream>
#include <limits.h>
using namespace std;



class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* getright(Node* curr ){
        while(curr->next){
            Node* forward = curr->next;
            if(curr->child){
                Node* childhead=curr->child;
                Node* childtail = getright(childhead);
                curr->next = childhead;
                childhead->prev=curr;
                curr->child=NULL;
                childtail->next=forward;
                forward->prev=childtail;                
                curr=childtail;
            }
            else{
                curr=forward;
            }
        }
        return curr;
    }
    
    Node* flatten(Node* head) {
        if(!head  || !head->next){
            return head;
        }
        getright(head);
        return head;
    }
};