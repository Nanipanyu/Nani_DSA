#include <iostream>
using namespace std;

//Given the head of a singly linked list and two integers left and right(index postions) where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list
//left and right are 1-indexed
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        ListNode* Left = NULL;
        ListNode* forward = NULL;
        ListNode* prev = NULL;
        int count=1;

        if(temp->next==NULL){
            return head;
        }
        if(left==right){
            return head;
        }
        while(temp!=NULL){
            forward = temp->next;
            if(count == left-1){
                Left=temp;
            }
            if( count>= left){
                temp->next = prev;
                prev = temp;
                if(count==right){
                    if(Left==NULL){            // if left is 1, then we are reversing from the head because we were not able to find the left node as it is the first node
                        head->next=forward;
                        head=temp;
                    }
                    else{
                        prev=Left->next;
                        Left->next=temp;
                        prev->next=forward;
                    }
                    break;
                }
            }
            temp=forward;
            count++;
        }
        temp=head;
        return temp;
    }
};


//Alterntate approach using a dummy node

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: move `prev` to the node before `left`
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: reverse sublist from `left` to `right`
        ListNode* curr = prev->next;
        ListNode* next = NULL;

        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};
