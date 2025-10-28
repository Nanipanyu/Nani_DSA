#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// https://leetcode.com/problems/diameter-of-binary-tree/
//Diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

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
    int dia(TreeNode* root,int &maxdia){
        if(!root){
            return 0;
        }
        int lefthght=dia(root->left,maxdia);
        int righthght=dia(root->right,maxdia);
        maxdia=max(maxdia,lefthght+righthght);
        return 1+max(lefthght,righthght);        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxdia=0;
        dia(root,maxdia);
        return maxdia;
    }
};