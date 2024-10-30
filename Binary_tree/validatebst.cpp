#include<iostream>
#include <climits>
using namespace std;

class BinaryTreeNode{
    public:
        int data;
        BinaryTreeNode*left;
        BinaryTreeNode* right;

        BinaryTreeNode(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }

};
bool isbst(BinaryTreeNode *root,int maxi,int mini){ //maxi and mini is to check if its child root are within the range of its parents as it should be in bst
    if(root==NULL){
        return true; 
    }
    int check=root->data;
    if(check<=maxi  && check>=mini){  //if nodes are valid (as in bst ) go further in tree
        bool left=isbst(root->left,check,mini);  //itshould be less than it parent
        bool right=isbst(root->right,maxi,check); //itshould be greater than it parent
        return left && right; // as moving up when going back return the intersection of true and false
    }
    else{
        return false;
    }

}

bool validateBST(BinaryTreeNode *root) {
    bool ans=isbst(root, INT_MAX,INT_MIN);
    return ans;
}