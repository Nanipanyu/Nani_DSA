#include <iostream>
#include <limits.h>
using namespace std;

// You are given the head of a linked list. Add two numbers represented by two linked lists and return the head of the resulting linked list.

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

    class Solution {
    public:

        ListNode* reverse(ListNode* head){  // Function to reverse the linked list
            ListNode* prev=NULL;
            ListNode*curr = head;
            ListNode* forward = NULL;
            while(curr!=NULL){
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
            }
            return prev;
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            l1 = reverse(l1);           // Step 1: Reverse the linked list because we need to add from the least significant digit/rightside
            l2 = reverse(l2);
            ListNode* head = NULL;
            ListNode* tail = NULL;
            int carry = 0;
            int val = 0;
            int digit = 0;
            while(l1!=NULL || l2!=NULL){
                if(l1==NULL && l2!=NULL){                       // If l1 is NULL, we only have l2 to add
                    if(carry!=0){                               // If there is a carry, we add it to the value of l2,then create a new node
                        digit=(carry+l2->val);
                        val=digit%10;
                        ListNode* temp = new ListNode(val);
                        tail->next = temp;
                        tail=temp;
                        l2=l2->next;
                    }
                    else{                                       // If there is no carry, we can directly link l2 to the tail
                        tail->next=l2;
                        break;
                    }
                    carry = digit/10;                             //it is in last so that it wont affect the next iteration
                }
                if(l2==NULL && l1!=NULL){
                    digit=(carry+l1->val);
                    val=digit%10;
                    if(carry!=0){
                        ListNode* temp = new ListNode(val);
                        tail->next = temp;
                        tail=temp;
                        l1=l1->next;
                    }
                    else{
                        tail->next=l1;
                        break;
                    }
                    carry = digit/10;
                }
                if(l1!=NULL && l2!=NULL){                   // If both lists are not NULL, we add the values
                    digit=l1->val+l2->val+carry;
                    val=digit%10;
                    carry=digit/10;
                    ListNode* temp = new ListNode(val);     // Create a new node with the value of the sum
                    if(head==NULL && tail==NULL){           // If this is the first node being added
                        head = temp; 
                        tail=temp;
                        l1=l1->next;
                        l2=l2->next;
                        continue;
                    }
                    tail->next=temp;
                    tail=temp;
                    l1=l1->next;
                    l2=l2->next;
                }
            }
            if(carry!=0){
                ListNode* temp = new ListNode(carry); 
                tail->next=temp;
            }
            head = reverse(head);
            return head;
        }
    };