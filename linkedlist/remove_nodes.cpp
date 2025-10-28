#include <iostream>
#include <limits.h>
using namespace std;

//You are given the head of a linked list.Remove every node which has a node with a greater value anywhere to the right side of it.
//Return the head of the modified linked list.

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:

// if we dont reverse the linked list, we will have to traverse the entire list for each node to check if it has a greater value to its right, which is inefficient.
// So, we reverse the linked list first, then we can keep track of the maximum value
     ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head); // Step 1

        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;
        ListNode* tail = dummy;
        int maxVal = INT_MIN;

        // Step 2: Keep only nodes >= max seen so far
        while (curr) {
            if (curr->val >= maxVal) {
                maxVal = curr->val;
                tail->next = curr;
                tail = curr;
            }
            curr = curr->next;
        }
        tail->next = nullptr; // break any leftover links

        return reverse(dummy->next);
    }
};