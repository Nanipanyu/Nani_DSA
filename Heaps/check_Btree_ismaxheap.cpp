#include<iostream>
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
class Solution {
  public:

  // counting no. of nodes in binary tree
      int count(struct Node* root){
          if(root==NULL){
              return 0;
            }
          int left=count(root->left);
          int right=count(root->right);
          int ans=1+left+right;
          return ans;
        }
      
      // checking if tree obeys CBT condition
      bool iscbt(struct Node* root,int index,int cnt){
          if(root==NULL){
              return true;
            }
          if(index>=cnt){  //if index>cnt (index=position of node(child))that means it has right child but no left child(disobeys CBT)
              return false;
            }
          else{
              bool left=iscbt(root->left,2*index+1,cnt);
              bool right=iscbt(root->right,2*index+2,cnt);
              return(left && right);
            }
          
        }
      
      //to check if it obeys max heap cond(i.e: parent node>child node)
      bool ismaxheap(struct Node* root){
          if(root->left==NULL && root->right==NULL){ //if leaf node then it obeys maxheap
              return true;
            }
          if(root->right==NULL){  //if right==NULL, then root should be greater than root->left for satisfying maxheap
              return(root->data > root->left->data);
            }
          else{
              bool left=ismaxheap(root->left);
              bool right=ismaxheap(root->right);
              return((root->data>root->left->data) && (root->data>root->right->data) && left && right); //take intersection of left& right & (root->data>root->left->data) && (root->data>root->right->data) for confirming CBT
          }
          
        }
  
  
        bool isHeap(struct Node* tree) {
            // code here
            int index=0;
            int cnt=count(tree);
            if(iscbt(tree,index,cnt) && ismaxheap(tree)){ //to satisfy maxheap, it should obey maxheap cond and CBT condn
                return true;
            }
            else{
                return false;
            }
        }
};