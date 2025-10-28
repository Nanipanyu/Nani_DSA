#include<iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> posn;
        int count=0;
        ListNode* temp = head;
        while(temp!=NULL){
            if(posn.find(temp)!=posn.end()){
                return temp;
            }
            posn[temp]=count;
            temp=temp->next;
            count++;
        }
        return NULL;   
    }
};

//Approach using Floyd's Cycle Detection Algorithm
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if there's a cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Cycle detected
                break;
            }
        }

        // No cycle
        if (!fast || !fast->next) return NULL;

        // Step 2: Find the cycle's starting node
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // Start of cycle
    }
};
