#include<iostream>
#include<queue>
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
Node* insertdata(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data){
        root->right=insertdata(root->right,data);
    }
    if(data<root->data){
        root->left=insertdata(root->left,data);
    }
    return root;
}

void takeinput(Node* &root){
    cout<<"Enter your Data to create BSt"<<endl; // you can take you input in one line with spaces and the loop will automatically take it one by one
    int data;
    cin>>data;
    while(data!=-1){
        root=insertdata(root,data);  
        cin>>data;                                                                                                                                                                                                                           
    }
}
void inorder(Node* root,vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    // cout<<root->data <<" ";
    v.push_back(root->data);
    inorder(root->right,v);
   // Quick tip , in Btree everytime in a recursive function after right child call ,you return to the parent ,which have the previous both left and right child
}
void preorder(Node* root,int &index,vector<int> arr){
    if(root==NULL){
        return;
    }
    // cout<<root->data<<" ";
    root->data=arr[index++];
    preorder(root->left,index,arr);
    preorder(root->right,index,arr);
}

int main(){
    Node* root=NULL;
    takeinput(root); //making a BST
    vector<int> v;
    inorder(root,v); //inerting the tree ele in a inorder vector = minheap vector
    int ind=0;
    preorder(root,ind, v); //treaversing over the tree preorderly and changing val of nodes with inorder vector ele, such that N<L<R,
}
