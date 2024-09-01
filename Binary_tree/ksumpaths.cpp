#include<iostream>
#include<vector>
using namespace std;

// question: if the path have sum of nodes =k, nodes in summation must be continuous, paht can start from anywhere and end anywhere, but must be continuous

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
  
    void solve(Node* root,int k,int &count,vector<int> path){
        if(root==NULL){  //base case
            return;
        }
        path.push_back(root->data); // putting the node values of path in vector
        solve(root->left,k,count,path);
        solve(root->right,k,count,path);
        // after completing 1 family
        int sum=0;
        for(int i=path.size()-1;i>=0;i--){  //check if the sum of nodes in the path=k ,but check from back, because then it will be unique to the latest nodes in the path, if u start from start(0) then it will account the sum for fromthe root
            sum=sum+path[i];
            if(sum==k){
                count++;
            }
        }
        path.pop_back(); // to remove the last added node and maintain the correct path state as recursion unwinds
    }
    int sumK(Node *root, int k) {
        // code here
        vector<int> v;
        int count=0;
        solve(root,k,count,v);
        return count;
    }
};