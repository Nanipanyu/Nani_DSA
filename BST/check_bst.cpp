#include<iostream>
#include<climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isbst(Node* root,int mini , int maxi){             // mini and maxi represent the range of valid values for the current subtree
        if(!root){
            return true;
        }
        if(root->data<mini || root->data>maxi){             // Check if the current node's value is within the valid range
            return false;
        }
        bool left = isbst(root->left,mini,root->data);      // Check if the left subtree is valid by sending the current root val as maxi to check the left subtree are smaller than that
        bool right = isbst(root->right,root->data,maxi);    // Check if the right subtree is valid by sending the current root val as mini to check the right subtree are greater than that
        return left&&right;
    }
    
    bool isBST(Node* root) {
        // Your code here
        bool ans = isbst(root,INT_MIN,INT_MAX);
        return ans;
    }
};