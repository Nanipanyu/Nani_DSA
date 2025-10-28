#include<iostream>
#include<vector>
#include<unordered_map>
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

    TreeNode* build(vector<int>& postorder,int &postorderind,int inorderstrt,int inorderend,unordered_map<int,int> &inmap){
        if(inorderstrt>inorderend){                                                      // Base case, if inorderstrt>inorderend i.e it has no subtree
            return NULL;
        }
        int rootval = postorder[postorderind--];                                           // Get the root value from postorder to make the root node and decrement the postorder index to move to next right node . 
        TreeNode* root = new TreeNode(rootval);

        root->right = build(postorder,postorderind,inmap[root->val]+1,inorderend,inmap);   // Build right subtree , by taking the next node from postorder and sending  the right index in inorder map of the current rootval, because the right subtree will always be in the right part of the inorder array
        root->left = build(postorder,postorderind,inorderstrt,inmap[root->val]-1,inmap);   // Build left subtree , by taking the next node from postorder and sending  the left index in inorder map of the current rootval, because the left subtree will always be in the left part of the inorder array
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inmap;
        for(int i = 0;i<inorder.size();i++){                                             // Create a map for indexposn of inorder values, basically it is to track right and left subtree
            inmap[inorder[i]]=i;
        }
        int postorderind = postorder.size()-1;                                            //starting from last element, because in postorder root node is in last
        TreeNode* head = build(postorder,postorderind,0,inorder.size()-1,inmap);
        return head;
    }
};