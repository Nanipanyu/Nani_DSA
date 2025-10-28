#include<iostream>
using namespace std;

//https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
//Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

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
    pair<int, TreeNode*> helper(TreeNode* node) {
        // Base case: a null node has no depth and no LCA.
        if (!node) {
            return {0, NULL};
        }

        // Recursively call for left and right children.
        pair<int, TreeNode*> left = helper(node->left);
        pair<int, TreeNode*> right = helper(node->right);

        // Get the depth from the left and right results.
        int left_depth = left.first;
        int right_depth = right.first;

        // Compare depths to decide what to return.
        if (left_depth > right_depth) {
            // If left is deeper, the LCA is in the left subtree.
            // Add 1 to the depth for the current level.
            return {left_depth + 1, left.second};
        } 
        else if (right_depth > left_depth) {
            // If right is deeper, the LCA is in the right subtree.
            return {right_depth + 1, right.second};
        } 
        else {
            // If depths are equal, the current node is the LCA.
            return {left_depth + 1, node};
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<int,TreeNode*> lca = helper(root);
        return lca.second;
    }
};