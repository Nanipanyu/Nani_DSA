
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. wehave to find the path with the maximum sum of values of nodes in the path.

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
    int maxi(TreeNode* root,int &maxsum){
        if(!root){
            return 0;
        }
        int leftsum = maxi(root->left,maxsum);                                                                     // Recursively calculate the maximum path sum for the left subtree
        int rightsum = maxi(root->right,maxsum);                                                                   // Recursively calculate the maximum path sum for the right subtree
        maxsum = max({maxsum,leftsum + rightsum + root->val,leftsum + root->val,rightsum + root->val,root->val});  // Update the maximum path sum considering the current node and its left and right children
        return max({max(leftsum,rightsum) + root->val,root->val});                                                 // Return the maximum path sum that can be extended to the parent node, which is either the current node's value(because curr node can be+ve and left and right can be -ve) or the current node's value plus the maximum of its left or right subtree sums
    }

    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;                                // Initialize maxsum to the smallest possible integer, it is not set to 0 because the path can include negative values.
        maxi(root,maxsum);                                 
        return maxsum;
    }
};