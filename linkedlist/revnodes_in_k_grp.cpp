#include <iostream>
#include <limits.h>
using namespace std;

// You are given the head of a linked list. Reverse the nodes of the linked list k at a time and return its modified head.
//Example: Given the linked list 1->2->3->4->5 and k = 2, you should return the linked list 2->1->4->3->5.

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);                          //dummy node to attach the reversed groups
        dummy.next = head;
        ListNode* cnt = head;
        int length = 0;
        int count = 1;
        while(cnt){
            length++;
            cnt=cnt->next;
        }
        if(k==0 || k==1 || k>length || head==NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = dummy.next;
        ListNode* prevgrpend = &dummy;                          // Pointer to the end of the previous group which will be used to connect to the end of the next reversed group
        ListNode* grpstart = curr;                              // Pointer to the start of the current group which will be attached to the start of next reversed group such that it is reversed
        while(length>=k){                                       // While there are at least k nodes left to reverse
            ListNode* next = curr->next;                       
            curr->next = prev;
            prev = curr;                                         //reversing process
            curr = next;
            if(count==k){                                        // If we have reversed k nodes, we need to connect the previous group end to the current group start
                prevgrpend->next=prev;                           // Connect the end of the previous group to the start of the current reversed group
                grpstart->next=curr;                             // Connect the start of the current reversed group to the next group
                prevgrpend=grpstart;                             // Update the previous group end for the next k group
                grpstart=curr;                                   // Update the start of the current group for the next k group
                count=0;
                length-=k;                                       // Decrease the length by k as we have processed k nodes
            }
            count++;
        }
        return dummy.next;        
    }
};