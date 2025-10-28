#include<iostream>
#include<climits>
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
    bool isBST(Node* root, int minVal, int maxVal) {
        if(!root) return true;
        if(root->data <= minVal || root->data >= maxVal) return false;
        return isBST(root->left, minVal, root->data) &&
               isBST(root->right, root->data, maxVal);
    }

    // Calculate size of subtree
    int size(Node* root) {
        if(!root) return 0;
        return 1 + size(root->left) + size(root->right);
    }
    
    int largestBst(Node *root) {
        if(!root) return 0;

        // If whole tree is BST, return its size
        if(isBST(root, INT_MIN, INT_MAX)) {
            return size(root);                         
        }
        // If not, check left and right subtrees, try to find smaller largest BST
        int left = largestBst(root->left);
        int right =  largestBst(root->right);

        //  check largest BST in left and right subtree
        return max(left,right);
        
    }
};