#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:

    TreeNode* build(vector<int>& preorder,int &preorderind,int inorderstrt,int inorderend,unordered_map<int,int> &inmap){
        if(inorderstrt>inorderend){                                                     // // Base case, if inorderstrt>inorderend i.e it has no subtree
            return NULL;
        }
        int rootval = preorder[preorderind++];                                          // Get the root value from preorder to make the root node and increment the preorder index to move to next left node . 
        TreeNode* root = new TreeNode(rootval);

        root->left = build(preorder,preorderind,inorderstrt,inmap[root->val]-1,inmap);   // Build left subtree , by taking the next node from preorder and sending  the left index in inorder map of the current rootval, because the left subtree will always be in the left part of the inorder array
        root->right = build(preorder,preorderind,inmap[root->val]+1,inorderend,inmap);   // Build right subtree , by taking the next node from preorder and sending  the right index in inorder map of the current rootval, because the right subtree will always be in the right part of the inorder array
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inmap;
        for(int i = 0;i<inorder.size();i++){
            inmap[inorder[i]]=i;                                                          // Create a map for indexposn of inorder values, basically it is to track right and left subtree
        }
        int preorderind = 0;                                                              //starting from first element, because in preorder root node is in first
        TreeNode* head = build(preorder,preorderind,0,inorder.size()-1,inmap);
        return head;
    }
};