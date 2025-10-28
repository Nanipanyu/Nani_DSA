#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
//zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool turn = true;                                                //turn to decide in which direction to traverse(true for left-to-right)
        stack<TreeNode*> sleft;                                          // stack for left-to-right traversal
        stack<TreeNode*> sright;                                         // stack for right-to-left traversal
        sright.push(NULL);
        sright.push(root);
        vector<vector<int>> ans;
        vector<int>bucket;
        TreeNode* temp = NULL;
        if(!root){
            return ans;
        }
        while(!sleft.empty() || !sright.empty()){                         //traverse until both stacks are empty
            if(!sleft.empty() && !turn){                                  //if left stack is not empty and it's left-to-right turn
                temp=sleft.top();
                sleft.pop();
            }
            else{                                                         //if right stack is not empty and it's right-to-left turn
                temp=sright.top();
                sright.pop();
            }
            if(!temp){                                                    //if temp is NULL,push the current bucket to the answer and change the direction of traversal(by turn)
                ans.push_back(bucket);
                bucket.clear();
                if(turn){
                    turn = false;
                }
                else{
                    turn = true;
                }
            }
            else{
                bucket.push_back(temp->val);
                if(turn){                                                 //if it's left-to-right turn, insert children from left to right
                    if(temp->left){
                        if(sleft.empty()){                                //only if child is not NULL, and stack is empty, first push NULL
                            sleft.push(NULL);
                        }
                        sleft.push(temp->left);
                    }
                    if(temp->right){
                        if(sleft.empty()){
                            sleft.push(NULL);
                        }
                        sleft.push(temp->right);
                    }
                }
                else{                                                      //if it's right-to-left turn, insert children from right to left
                    if(temp->right){
                        if(sright.empty()){
                            sright.push(NULL);
                        }
                        sright.push(temp->right);
                    }
                    if(temp->left){
                        if(sright.empty()){
                            sright.push(NULL);
                        }
                        sright.push(temp->left);
                    }
                }
            }
        }
        return ans;    
    }
};