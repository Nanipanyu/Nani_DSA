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
    int mini(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root->val;
    }

    TreeNode* del(TreeNode* root ,int key){
        if(!root){
            return NULL;
        }
        if(root->val == key){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            if(!root->left && root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(root->left && !root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } 
            if(root->left && root->right){
                int temp = mini(root->right);
                root->val = temp;
                root->right = del(root->right,temp);
                return root;
            }             
        }
        if(root->val>key){
            root->left = del(root->left,key);
        }
        else{
            root->right = del(root->right,key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* head = del(root,key);
        return head;
    }
};