#include <iostream>
using namespace std;    
//Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            if (!head || !head->next ) return head;
            ListNode* evenhead = head->next;
            ListNode* even = head->next;
            ListNode* odd = head;
            
            while(even && even->next){
                odd->next=even->next;
                odd=odd->next;

                even->next = odd->next;
                even=even->next;
            }
            odd->next=evenhead;
            return head;
        }
    };