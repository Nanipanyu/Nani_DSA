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

//here making left subtree LL first then attaching its tail with root node then making right subtree linked list and attaching its head with root node
void bst_to_ll(Node *root,Node *&tail){
    if(root==NULL){
        return ;
    }
    bst_to_ll(root->left,tail);
    tail->right=root; //coneect tail->right(node which has been visited) with root(where we are now)
    if(tail!=NULL){
        root->left=tail; // making a doubly ll 
    }
    tail=root;  // make the visited left node as tail  when moving to right
    bst_to_ll(root->right,tail);
}

//here making right subtree LL first then attaching its head with root node then making left subtree linked list and attaching its tail with root node
void bst_to_ll(Node *root,Node *&head){
    if(root==NULL){
        return ;
    }
    bst_to_ll(root->right,head);
    root->right=head;  //connect root->right with head node which is the node that has been visited
    if(head!=NULL){
        head->left=root; //making a doubly linked list
    }
    head=root; // make the visited right node as head  when moving to left
    bst_to_ll(root->left,head);
}

void inorder(Node* root, vector<Node*> &v){  //creating inorder vector from BST
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}
Node* flatten(Node* root)
{
    vector<Node*> v;
    inorder(root,v); 
    for(int i=0;i<v.size()-1;i++){  //converting inorder(sorted)BST into ll by making there left=NULL and there right->next value in vector
        v[i]->left=NULL;
        v[i]->right=v[i+1];
        if(i==v.size()-2){
            v[v.size()-1]->left=NULL; //if it is the last value of vector ,right most val of BST, make it both left and right both NULL
            v[v.size()-1]->right=NULL;  
        }
    }
    return v[0];
}