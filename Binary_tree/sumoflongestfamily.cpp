#include <iostream>
#include <vector>
#include<queue>
#include <climits>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left=NULL;
        right=NULL;
    }

};


node* buildtree(node* root){
    cout<<"Enter node value"<<" ";
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data for left of "<<" "<<root->data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter the data for right of  "<<" "<<root->data<<endl;
    root->right=buildtree(root->right); 

    return root;
}
void traversal(node* root, int sum,int count, int &maxi,queue<int> &q){
    if(root==NULL){
        return;
    }
    sum=sum+root->data; // keep track of sum of nodes before going to next node, because we may come to same node for traversing its different family, so we will be need the sum upto that parent node
    count++; // keep track of count of child nodes before going to next node, because we may come to same node for traversing its different family, so we will be need the count upto that parent node
    if(root->left==NULL && root->right==NULL){  //if reached a leaf node
        if(count>q.front()){ //compare the count of nodes to count of previous highest family stored in queue 
            maxi=sum;  //if count is greater store the sum of nodes in maxi
            q.push(count); //push the new max count
            q.pop(); //pop the old count
        }
    }
    traversal(root->left,sum,count,maxi,q);
    traversal(root->right,sum,count,maxi,q);
}

int mainCode(node* root){
    int maxi=0; //to store the sum fo longest family
    queue<int> q;  //to store the count of members in family
    q.push(-1);  
    int sum=0;  //to store sum of nodes
    int count=0;   // to keep count of members in family
    traversal(root,sum,count,maxi,q);
    return maxi;
}

int main()
{
    node*root=NULL;
    root=buildtree(root);
    int maxi=mainCode(root);
    cout<<"sum of longest chain is"<<" "<<maxi<<endl;
    return 0;
}