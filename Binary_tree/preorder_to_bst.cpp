#include<iostream>
#include<vector>
#include<climits>
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
// we know that preorder is(NLR) so the first element in array is the head node, then comes the left nodes, then the right nodes 

Node* makeBST(vector<int> &preorder,int maxi,int mini,int &i,int &size){
    //base case when value of array is not under the range of node subtree, then return NULL and change direction(maybe right subtree) and then try to find place for the node there
    if(preorder[i]<mini || preorder[i]>maxi || i>size){   
        return NULL;
    }
    Node* root=new Node(preorder[i]); //make node for the preorder value
    i++;
    root->left=makeBST(preorder,root->data,mini,i,size); //move left and try to find a place for the array value there by checking range of left subtree
    root->right=makeBST(preorder,maxi,root->data,i,size); //move right and try to find a place for the array value there by checking range of right subtree
    return root;

}
Node* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    pair<int,int>range(INT_MIN,INT_MAX);
    int i=0;
    int maxi=INT_MAX;
    int mini=INT_MIN;
    int size=preorder.size()-1;
    Node* head=makeBST(preorder,maxi,mini,i,size);
    return head;
}

// Other approaches could be
//(i) take the array values as input just make a tree according to BST rules but time complexity will be O(n2)
//(iii) find the inorder array from preorder array then amke the tree using preorder and inorder, there is a method