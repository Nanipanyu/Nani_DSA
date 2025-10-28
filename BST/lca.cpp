#include<iostream>
using namespace std;
 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       while (root != NULL) {
            // Case 1: Both p and q's values are greater than the current node's value.
            // This means both nodes are in the right subtree, so we move right.
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // Case 2: Both p and q's values are smaller than the current node's value.
            // This means both nodes are in the left subtree, so we move left.
            else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // Case 3: The paths split or one of the nodes is the current node.
            // This happens if one value is smaller and the other is larger, or if
            // one of the nodes (p or q) is equal to the current node.
            // In this case, the current node is the LCA.
            else {
                return root;
            }
       }
       return root;
    }
};