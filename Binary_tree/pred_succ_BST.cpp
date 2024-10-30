#include<iostream>
#include <climits>
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
// to find predecessor and succesor in inorder BST
pair<int, int> predecessorSuccessor(TreeNode *root, int key)  
{
    int predecessor=-1;   //setting it with to -1 , so if it is a edge node its pred or succ will be-1
    int successor=-1;
    TreeNode *temp=root;
    //finding the key node
    while(temp->data!=key){
        if(temp->data>key){ //moving to left if temp>key
            successor=temp->data;   // storing previous node while moving to left because it can be a successor to key, and also because we wont be able to retrieve it if the key is the edge node(with no children), then this will be the succesor
            temp=temp->left;
        }
        else{   //moving to right if temp<key
            predecessor=temp->data;  // storing previous node while moving to right because it can be a predecessor to key, and also because we wont be able to retrieve it if the key is the edge node(with no children), then this will be the succesor
            temp=temp->right;
        }
    }
    
    TreeNode *pred=temp->left;
    while(pred!=NULL){  //well if the key has left children nodes then its predecessor can be found in left nodes(biggest node in the left childrens) but if no left childrennodes than pred will be from above or -1
        predecessor=pred->data;
        pred=pred->right;
    }
    TreeNode *succ=temp->right;
    while(succ!=NULL){
        successor=succ->data;  //well if the key has right children nodes then its successor can be found in right nodes(smallest node in the right childrens) but if no right childrennodes than succ will be from above or -1
        succ=succ->left;
        
    }
    pair<int,int>ans(predecessor,successor);
    return ans;
}