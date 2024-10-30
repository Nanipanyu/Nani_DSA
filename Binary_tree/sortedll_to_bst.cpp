#include<iostream>
#include <climits>
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
 //here root is the mid node of Linked list and n is the count of no. of nodes
Node* sortedlltobst(Node *root,int n){
    if(root==NULL || n==0){
        return NULL;
    }
    Node *left=sortedlltobst(root,n/2);
    Node *head=root;
    head->left=left;
    head->right=sortedlltobst(root,n-(n/2)-1);
    return head;
}