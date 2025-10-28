#include<iostream>
#include<map>
#include<queue>
#include<vector>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int,int> posn;                                                  // Map to store the rightmost value at each level
        queue<pair<TreeNode* , int>>q;
        if(!root){
            return ans;
        }
        q.push({root,0});
        q.push({NULL,0});
        int i = 1;                                                         //i to point to the current level
        while(!q.empty()){
            pair<TreeNode*,int> current = q.front();
            TreeNode* temp = current.first;                                 // Pointer to the current node
            int row = current.second;                                       // Row (level) of the current node
            q.pop();
            if(!temp){                                                      // If current node is NULL
                if(q.empty()){
                    break;
                }
                else{                                                       // If current node is NULL and queue is not empty, it is the end of the current level, so add a new level marker
                    q.push({NULL,i});
                    i++;                                                    // Increment the level/row counter
                }
            }
            else{
                if(posn.find(row)==posn.end()){                             // If this is the first time we are visiting this level(from right side) insert the value
                    posn[row] = temp->val;
                }
                if(temp->right){                                            // If right child exists, add it to the queue first because we want right view
                    q.push({temp->right,i});
                }
                if(temp->left){
                    q.push({temp->left,i});
                }
            }
        }
        for(const auto& pair : posn){
            ans.push_back(pair.second);
        }
        return ans;
    }
};