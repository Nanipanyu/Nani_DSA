#include<iostream>
#include<limits.h>
using namespace std;

// height of a binary tree is the number of edges in the longest path from the root to a leaf node.
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
  public:
  
    void hght(Node* root,int count,int &maxcnt){
        if(root==NULL){
            return;
        }
        if(!root->left && !root->right){                       //if it is a leaf node then we check if the count is greater than maxcnt
            maxcnt=max(count,maxcnt);
        }
        hght(root->left,count+1,maxcnt);
        hght(root->right,count+1,maxcnt);
    }
    
    int height(Node* node) {
        // code here
        if(!node || (!node->left && !node->right)){
            return 0;
        }
        int count=0;
        int maxcnt=INT_MIN;
        hght(node,count,maxcnt);
        return maxcnt;
    }
};