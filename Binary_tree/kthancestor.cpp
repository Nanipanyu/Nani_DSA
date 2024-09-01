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

Node* buildtree(Node* root){
    int data;
    cout<<"Enter the data for the node"<<" "<<endl;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of"<<" "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data for inserting in right of"<<" "<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}
Node* tra(Node* root,int k, int node,int &count){
    if(root==NULL){  //base case if reached an end
        return NULL;
    }
    if(root->data==node){  // if you found the node whose ancestors u want to find then return, dont go nay deeper into that family
        count++;  // increase the count by one for your direct parent 
        return root;
    }
    Node* left=tra(root->left,k,node,count);
    Node* right=tra(root->right,k,node,count);
    if((left!=NULL || right!=NULL) && count==k){  // as recursion unwinds if its left ofr right is not null(that node family has the given node) and if count==k we have reached the kth ancestor so now return that node and pass it to top as recursion unwinds
        count++; // we increase count so that further parent wont be considerd
        return root;
    }
    if(left!=NULL && right==NULL){ //if left!=null,and count!=k ,i,e that node is not the kth ancestor but the finding node is in its family line in its leftchild family  
        count++;   //so inc the count to keeptrack of no. of ancestor it has reached. and keep returning the left val
        return left;
    }
    if(left==NULL && right!=NULL){ //similar as above
        count++;
        return right;
    }
    if(left==NULL && right==NULL){
        return NULL;
    }

}
int kthAncestor(Node *root, int k, int node)  //will return the int value of kth ancestor
{   
    // Code here
    int count=0;  //sending count as reference to store the count of ancestor as recursion unwinds
    Node* ans=tra(root,k,node,count); //sending for recursion
    if(ans!=NULL){  // If there is a ancestor
        return ans->data;
    }
    else{
        return -1;
    }
}

int main(){
    Node* root= NULL;
    root=buildtree(root);
    int k=2;
    int node=8;
    int ans=kthAncestor(root,k,node);
    //1 3 7 -1 8 -1 -1 10 -1 12 -1 -1 5 6 -1 15 2 -1 -1 -1 9 -1 -1 -1
    cout<<"nas is"<< " "<<ans;
}