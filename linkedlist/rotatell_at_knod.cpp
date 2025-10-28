#include <iostream>
#include <limits.h>
using namespace std;

// You are given the head of a linked list and an integer k. Rotate the linked list to the right by k places.
// Example: Given the linked list 1->2->3->4->5 and k = 2, you should return the linked list 4->5->1->2->3.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:

//Method1
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next==NULL || k==0){
            return head;
        }
        ListNode* temp = head;
        ListNode* newhead = head;
        int length = 1;
        int itr = 0;
        while(temp->next){
            length++;
            temp=temp->next;
        }
        k = k%length;                               //for if k is greater than length
        temp = head;
        ListNode* prev = NULL;                      // Pointer to keep track of the previous node before newhead so to set it to NULL
        while(temp->next!=NULL){
            if(k==0){
                return head;
            }
            if(itr<(length-k)){                     //Find the new head position
                prev=temp;
                temp=temp->next;
                newhead = temp;
                itr++;
            }
            else{
                temp=temp->next;                     // Continue traversing temp until we reach the end of the list so that we can set the next of the last node to head
            }
        }
        prev->next=NULL;
        temp->next = head;
        return newhead;
    }

    //Method2 
    ListNode* rotateRight2(ListNode* head, int k) {       
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Compute the length and connect tail to head to make it circular
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        temp->next = head;  // Make it a circular list

        // Step 2: Find the new tail: (length - k % length - 1)th node
        k = k % length;
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }

        // Step 3: Break the loop and set new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};