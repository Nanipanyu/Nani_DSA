#include<iostream>
#include<climits>
using namespace std;
 // given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

//so basically our approach is finding the two nodes that are not following the BST property, and swap them back
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
    void check(TreeNode* root,TreeNode* &prev,TreeNode* &first,TreeNode* &second){                       //we will be traversing in inorder,by bst property in inorder it should be sorted
        if (!root) return;

        check(root->left,prev,first,second);

        if (prev && prev->val > root->val) {                                                            //if the current node is less than the previous node, we have found a violation
            if (!first) {
                first = prev;   // first wrong node
            }
            second = root;       // second wrong node (updated every time)                              
        }
        prev = root;                                                                                    // update previous node

        check(root->right,prev,first,second);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = new TreeNode(INT_MIN);                                       //to store the previous node
        TreeNode* first = NULL;                                                      //to store the first wrong node
        TreeNode* second = NULL;                                                     //to store the second wrong node
        check(root,prev,first,second);
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};