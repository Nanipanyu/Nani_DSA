#include<iostream>
#include<vector>
using namespace std;

class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    void find(Node* root, int key, Node* &pred, Node* &succ) {
        if (!root) return;

        if (root->data == key) {
            // predecessor = rightmost node of left subtree
            if (root->left) {
                Node* temp = root->left;
                while (temp->right) temp = temp->right;
                pred = temp;
            }

            // successor = leftmost node of right subtree
            if (root->right) {
                Node* temp = root->right;
                while (temp->left) temp = temp->left;
                succ = temp;
            }
        } 
        else if (root->data > key) {
            succ = root;   // current node could be successor
            find(root->left, key, pred, succ);
        } 
        else {
            pred = root;   // current node could be predecessor
            find(root->right, key, pred, succ);
        }
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pred = nullptr;
        Node* succ = nullptr;
        find(root, key, pred, succ);
        return {pred, succ};
    }
};

