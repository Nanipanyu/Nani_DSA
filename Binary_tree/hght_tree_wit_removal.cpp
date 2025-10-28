
#include <vector>
#include <limits.h>
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

    void hght(TreeNode* root,int count,int &maxcnt,int tostop){
        if(!root){
            return;
        }
        if((!root->left && !root->right) || (!root->left && root->right->val==tostop) ||(!root->right && root->left->val==tostop)){
            maxcnt=max(maxcnt,count);
        }
        if(root->left && root->left->val!=tostop){
            hght(root->left,count+1,maxcnt,tostop);
        }
        if(root->right && root->right->val!=tostop){
            hght(root->right,count+1,maxcnt,tostop);
        }
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> heights;
        for(int i=0;i<queries.size();i++){
            int maxcnt = INT_MIN;
            hght(root,0,maxcnt,queries[i]);
            heights.push_back(maxcnt);
        }
        return heights;
    }
};