#include<iostream>
#include<limits.h>
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

    int checkheight(TreeNode* root){
        if(!root){
            return 0;
        }
        int lefttree=checkheight(root->left);
        if(lefttree==-1) return -1;
        int righttree=checkheight(root->right);
        if(righttree==-1) return -1;
        if(abs(lefttree-righttree)>1) return -1;
        return max(lefttree,righttree)+1;

    }
    bool isBalanced(TreeNode* root) {
        return checkheight(root) != -1;
    }
};