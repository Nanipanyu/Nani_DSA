#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
        int data;
        Node*left;
        Node* right;

        Node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }

};
// basically this question is to check if there is a pair of node in BST such that their sum is equal to a target value

void inorder(Node* root,vector<int> &v){ //converting BST into sorted inorder vector
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

bool twoSumInBST(Node* root, int target){
	//Write your code here
    vector<int> v;
    inorder(root,v);
    int i=0;
    int j=v.size()-1;
    // we will use double pointer andtraverse the vector from start and end
    while(i<j){
        int sum=v[i]+v[j];
        if(sum==target){ //satisfied condition
            break;
        }
        else if(sum>target){ //if sum>target, then we need to take one of the value a little small to lower the sum we can only move j--
            j--;
        }
        else if(sum<target){ //if sum<target, then we need to take one of the value a little bigger to increase the sum we can only move i++
            i++;
        }
    }
    if(i<j){
        return 1;
    }
    else{
        return 0;
    }

}