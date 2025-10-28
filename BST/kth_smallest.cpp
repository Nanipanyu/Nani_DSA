#include<iostream>
using namespace std;
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
//Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.


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

    // traverse in inorder to find the correct ordering of where the smallest kth element is 
    void getans(TreeNode* root,int &k,int &ans){
        if(!root){
            return ;
        }
        getans(root->left,k,ans);
        if(ans != -1 ){                                  //if ans is found
            return;
        }
        // 2. "Visit" the current node.
        // Decrement the countdown.
        k--;

        // If the countdown hits zero, this is the k-th smallest element.
        if(k==0){
            ans=root->val;
        }
        getans(root->right,k,ans);               
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        getans(root,k,ans);
        return ans;
    }
};