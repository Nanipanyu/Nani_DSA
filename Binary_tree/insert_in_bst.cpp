#include<iostream>
using namespace std;

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

    TreeNode* insert(TreeNode* root, int val){
        if(!root){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        if(root->val>val){
            root->left = insert(root->left,val);
        }
        else{
            root->right = insert(root->right,val);
        }
        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        insert(root,val);
        return root;
    }
};