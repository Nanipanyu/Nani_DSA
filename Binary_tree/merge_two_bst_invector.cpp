#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
    public:
        int data;
        TreeNode*left;
        TreeNode* right;

        TreeNode(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }

};

//converting BStree into a sorted vector using morristraversal
vector<int> tree_to_ll(TreeNode *root){
    vector<int> v;
    TreeNode *curr=root;
    TreeNode *pre;
    int count=0;

    while(curr!=NULL){
        if(curr->left==NULL){
            v.push_back(curr->data);
            curr=curr->right;
        }
        else{
            pre=curr->left;
            while(pre->right!=NULL && pre->right != curr){
                pre=pre->right;
            }
            if(pre->right==NULL){
                pre->right=curr;
                curr=curr->left;
            }
            else if(pre->right==curr){
                v.push_back(curr->data);
                pre->right=NULL;
                curr=curr->right;
            }
        }
    }
    return v;
}

//merging 2vectors into 1 in sorted order
vector<int> ll_t0_vec(vector<int> root1, vector<int> root2){
    vector<int> ans;
    int i=0;
    int j=0;

    while(i<root1.size() || j<root2.size()){
        if(i==root1.size() && j<root2.size()){
            while(j!=root2.size()){
                ans.push_back(root2[j]);
                j++;
            }
            continue;
        }
        else if(j==root2.size() && i<root1.size()){
            while(i!=root1.size()){
                ans.push_back(root1[i]);
                i++;
            }
            continue;
        }
        if(root1[i]>root2[j]){
            ans.push_back(root2[j]);
            j++;
        }
        else{
            ans.push_back(root1[i]);
            i++;
        }
    }
    return ans;
}

//Here given 2 BSt we merge them in a vector together in sorted order  
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> root3;
    vector<int> root4;
    root3=tree_to_ll(root1); //converting to inorder vector
    root4=tree_to_ll(root2); //converting to inorder vector
    vector<int> ans=ll_t0_vec(root3,root4); //merging two vectors
    return ans;
}

//Another question could be build BSt from merging 2BST , then we can use the merged vector and build a balanced BST
//If asked to merge 2BST without using extraspace , then we have to convert them both into linkedlist then merge the ll(sorted) then make final bst from ll 