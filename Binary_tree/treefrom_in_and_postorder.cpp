#include<iostream>
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

int findposition(int n,int ele,int in[]){
        for(int i=0;i<n;i++){
            if(in[i]==ele){
                return i;
            }
        }
        return -1;
    }
  
    Node* solve(int n,int in[],int post[],int &index,int poststr,int postend){  //similar to building tree from inorder and preorder, but here we build the right side of postorder array and build first the right branches because postorder:L:R:N 
        if(index<0 || postend<poststr){
            return NULL;
        }
        int ele=post[index--];
        Node* root=new Node(ele);
        int pos =findposition(n,ele,in);
        root->right=solve(n,in,post,index,pos+1,postend);
        root->left=solve(n,in,post,index,poststr,pos-1);
        return root;
    }

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
        int postindex=n-1;
        Node* root=solve(n,in,post,postindex,0,n-1);
        return root;
    }

    int main(){
        int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
        int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
        int n=8;
        Node* root = buildTree(n, in, post);
    }