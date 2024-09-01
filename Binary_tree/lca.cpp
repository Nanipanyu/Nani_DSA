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

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL){
           return NULL;  //return NULL to your direct parent
       }
       if(root->data==n1 || root->data==n2){
           return root;  //return yourself to the direct parent
       }
       Node* leftans=lca(root->left,n1,n2);
       Node* rightans=lca(root->right,n1,n2);

       //after checking both your left and right childs, basically this steps are for returning your lca in the recursion loop
       if(leftans!=NULL && rightans!=NULL){
           return root;   //this condn is if you found parent(i.e both left and right child) then return yourself to direct parent
       }
       else if(leftans!=NULL && rightans==NULL){
           return leftans;  //if right childs are NULL then return leftchild
       }
       else if(leftans==NULL && rightans!=NULL){
           return rightans;   //if left childs are NULL then return rightchild
       }
       else{
           return NULL;
       }
        
    }
};