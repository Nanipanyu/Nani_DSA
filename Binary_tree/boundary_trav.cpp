#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
  
    bool isleaf(Node *root){
        if(!root->left && !root->right){
            return true;
        }
        return false;
    }
  
    void addleft(Node *root,vector<int> &ans){
        if(!root->left){
            return;
        }
        Node *curr=root->left;
        while(!isleaf(curr)){
            ans.push_back(curr->data);
            if(curr->left){
                curr=curr->left;
            }
            else if(curr->right){
                curr=curr->right;
            }
        }
    }
    void addleaf(Node *root,vector<int> &ans){
        if(!root){
            return;
        }
        if(isleaf(root)){
            ans.push_back(root->data);
            return;
        }
        addleaf(root->left,ans);
        addleaf(root->right,ans);
    }
    void addright(Node *root,vector<int> &ans){
        if(!root->right){
            return;
        }
        stack<int> s;
        Node *curr=root->right;
        while(!isleaf(curr)){
            s.push(curr->data);
            if(curr->right){
                curr=curr->right;
            }
            else if(curr->left){
                curr=curr->left;
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        
        if(!root){
            return ans;
        }
        if(!isleaf(root)){
            ans.push_back(root->data);
        }
        addleft(root,ans);
        addleaf(root,ans);
        addright(root,ans);
        return ans;
    }
};