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

// Approach1 - inorder traversing and storing nodes in vector so that it is sorted and then finding kth smallest element from vector
void kele(Node* root,vector<int> &v){
    if(root==NULL){
        return;
    }
    kele(root->left,v);
    v.push_back(root->data);
    kele(root->right,v);

}

int kthSmallest(Node* root, int k){
    // Write your code here.
    vector<int> v;
    kele(root,v);
    if(k <= v.size()){
        return v[k - 1];
    }
    else{
        return -1;
    }
}


// Approach2 - inorder traversing and keeping count of nodes as it reach a node(in LNR) ,using that count to return the kth smallest value(as that count will increase with inorder(in sorted fashion))
void kele(Node* root,int &c,int &ans,int k){
    if(root==NULL){
        return;
    }
    kele(root->left,c,ans,k);
    c++;
    if(c==k){
        ans=root->data;
    }
    kele(root->right,c,ans,k);
}

int kthSmallest(Node* root, int k){
    // Write your code here.
    int count=0;
    int ans=-1;
    kele(root,count,ans,k);
    return ans;
}