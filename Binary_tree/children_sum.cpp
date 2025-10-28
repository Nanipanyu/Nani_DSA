#include<iostream>
using namespace std;
 //https://www.geeksforgeeks.org/problems/children-sum-parent/1
 //Children Sum Property. In this property, each non-leaf node must have a value equal to the sum of its left and right children's values. A NULL child is considered to have a value of 0, and all leaf nodes are considered valid by default.

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
  
    int trav(Node *root){
        if(!root){                                                    //if root is null return value will be 0;
            return 0;
        }
        if(!root->left && !root->right){                              //if root is leaf node return its value, because if we traverse further to its children, we will get 0's whose sum will not be equal to its parent(leafnode); making the ans false(which should not be)
            return root->data;
        }

        int left = trav(root->left);                                 //traverse left subtree and get its sum
        int right = trav(root->right);                               //traverse right subtree and get its sum

        if(left==-1 || right==-1){                                   //if any of the subtree was/is invalid, return -1
            return -1;
        }

        if(left + right != root->data){                              //if sum of left and right child is not equal to root, return -1, to make the whole subtree invalid
            return -1;
        }
        else{                                                        //if both children sum is = root i.e subtree is valid, return the sum of their values/which is the node value itself
            return root->data;
        }
    }
    
    int isSumProperty(Node *root) {
        // code here
        int ans = trav(root);
        if(ans==-1){
            return 0;
        }
        return 1;
        
    }
};