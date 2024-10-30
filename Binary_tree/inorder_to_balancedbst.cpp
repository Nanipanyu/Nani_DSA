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

void inorder(Node* root,vector<Node*> &v){ //converting  bst into inorder vector
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}
Node* makebst(int s,int e,vector<Node*> &v){ //making BST from inorder vector of unbalanced BST
// since inorder is:LNR , so we will try to create equal(equal no. of nodes) subtrees on both sides, for balanced bst, by using mid values of vector which is the node in LNR
    if(s>e){
        return NULL ;
    }
    int mid=(s+e)/2;
    Node* midnode=v[mid]; //getting mid node i.e root node for each tree or sub tree
    midnode->left=makebst(s,mid-1,v); //creating leftsubtree for node from left of midnode vector 
    midnode->right=makebst(mid+1,e,v); //creating rightsubtree for node from right of midnode vector
    return midnode;
}
Node* balancedBst(Node* root) {
    // Write your code here.
    vector<Node*> v;
    inorder(root,v);  //converting the tree into a inorder(sorted) BST
    int s=0;
    int e=v.size()-1;
    Node* head=makebst(s,e,v); //make BST from inorder vector
    return head;
}