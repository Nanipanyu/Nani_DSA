#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node*left;
        node* right;

        node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }

};
node* buildtree(node* root){
    int data;
    cout<<"Enter the data for the node"<<" "<<endl;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of"<<" "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data for inserting in right of"<<" "<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}
void buildfromlevelorder(node* &root){  //taking input in level order
    queue<node*> q;
    cout<<"Enter your data for node"<<endl;
    int d;
    cin>> d;
    root=new node(d);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
            cout<<"Enter data in left of"<<" "<<temp->data<<endl;
            int d;
            cin>>d;   
            if(d!=-1){
                node* leftdata=new node(d);
                temp->left=leftdata;
                q.push(leftdata);
            }
            cout<<"Enter data in right of"<<" "<<temp->data<<endl;
            int f;
            cin>>f;  
            if(f!=-1){
                node* rightdata=new node(f);
                temp->right=rightdata;
                q.push(rightdata);
            }
    }
}
void leveltra(node* root){  //to print in level order
    queue<node*> q;
    q.push(root);
    q.push(NULL);// to have a checker so we can print level order by using endl
    cout<<"level order traversal is"<<endl;
    while(!q.empty()){
        node* temp=q.front();
        q.pop();// after printing each ele pop it
        if(temp==NULL){  //if there is null we need to change our level using seperator
            cout<<endl;
            if(!q.empty()){
                q.push(NULL); //if queue is not empty after a NULL then there are all elements of the next level in queue so put a NULL for that level so it can be seperated later
            }
        }
        else{ //if there is data in temp push the left and right data of it in queue
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data <<" ";
    inorder(root->right);
   // Quick tip , in Btree everytime in a recursive function after right child call ,you return to the parent ,which have the previous both left and right child
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    node*root=NULL;
    buildfromlevelorder(root);
    leveltra(root);
    // root=buildtree(root);
    // postorder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
}