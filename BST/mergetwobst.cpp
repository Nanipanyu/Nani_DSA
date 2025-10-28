#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
  public:
    void bsttoll(Node* root, Node* &head, Node* &prev){                                            //bst to linked list in inorder 
       if (!root) return;

        // Traverse left
        bsttoll(root->left, head, prev);
    
        // Process root
        if (!head){
            head = root;   // first node becomes head
        } 
            
        if (prev){
           prev->right = root; 
        } 
        root->left = NULL;  // left should be null in linked list
        prev = root;
    
        // Traverse right
        bsttoll(root->right, head, prev);
    }
    
    Node* mergell(Node *root1,Node *root2){                                                    //mergingtwoll in sorted order
        Node* dummy = new Node(-1);
        Node *tail = dummy;
        while(root1 || root2){
            if(root1 && root2){
                if(root1->data<root2->data){
                    tail->right = root1;
                    root1=root1->right;
                }
                else{
                    tail->right = root2;
                    root2=root2->right;
                }  
            }
            else if(root1 && !root2){
                while(root1){
                    tail->right = root1;
                    root1=root1->right;
                    tail=tail->right;
                }
            }
            else if(!root1 && root2){
                while(root2){
                    tail->right = root2;
                    root2=root2->right;
                    tail=tail->right;
                }
            }
            tail=tail->right;
        }
        return dummy->right;
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        Node *head1 = NULL;
        Node *prev = NULL;
        bsttoll(root1,head1,prev);      
        Node *head2 = NULL;
        prev = NULL;
        bsttoll(root2,head2,prev);
        Node *finalhead = mergell(head1,head2);
        vector<int> ans;
        while(finalhead){
            ans.push_back(finalhead->data);
            finalhead = finalhead->right;
        }
        return ans;
    }
};