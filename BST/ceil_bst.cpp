#include<iostream>
using namespace std;

//Find ceil in a bst : given a int x find the greatest element in the bst which is greater than or equal to x

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
  
    int ans = -1;
        
    int findCeil(Node* root, int x) {
        // code here
        if(!root){
            return -1;
        }
        if(root->data == x){
            return root->data;
        }
        
        if(root->data>x){
            ans = findCeil(root->left,x);
        }
        else{
            ans = findCeil(root->right,x);
        }
        if(ans<x && root->data>x){                  // If the current node is greater than x and the previous ans was less than x, and it has no children to check on update ans
            ans = root->data;
        }
        return ans;
    }
};
