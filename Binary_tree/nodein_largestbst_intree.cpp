#include<iostream>
#include<climits>
#include<queue>
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
 //we made a datastructure to help us  to keep track if a subtree isBST or Not, and simultaneously keep count of nodes 
class info{
    public:
        int maxi;
        int mini;
        bool isbst;
        int size;
};

info solve(Node *root,int &ans){
    if(root==NULL){
        return{INT_MIN,INT_MAX,true,0};  //when reached NULL return then maxi=-inf and mini=Inf so  that leaf node always satisfies as a BST
    }
    info left=solve(root->left,ans);  //keep a info of left subtree(/node)
    info right=solve(root->right,ans); //Keep a info of right subtree(/node)

    info currNode; //info of curr node(parent node of left and right subtree(/node))
    currNode.size=left.size + right.size +1; //size of tree from that currNode(tree below it)
    currNode.maxi=max(root->data,right.maxi); // max value of tree from that currNode(tree below it)
    currNode.mini=min(root->data,left.mini); // min value of tree from that currNode(tree below it)

    if(left.isbst && right.isbst && (root->data>left.maxi && root->data<right.mini)){  //check if currNode(tree below it) is a BST or node with the folllowing condition in if()
        currNode.isbst=true;  //if satisfies then set .isbst of currNode(tree of currNode) as a bst int its info
    }
    else{
        currNode.isbst=false;
    }
    if(currNode.isbst){
        ans=max(ans,currNode.size); //if currNode(its tree below) is a BST then update ans(no. of nodes) as the size of currNode tree.
    }
    return currNode;

}

int largestBST(Node *root){
    // Write your code here.
    int maxsize=0;
    info temp=solve(root,maxsize);
    return maxsize;
}