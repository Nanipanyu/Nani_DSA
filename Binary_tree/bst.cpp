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
void leveltra(Node* root){  //to print in level order
    queue<Node*> q;
    q.push(root);
    q.push(NULL);// to have a checker so we can print level order by using endl
    cout<<"level order traversal is"<<endl;
    while(!q.empty()){
        Node* temp=q.front();
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
int minimum(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

Node* deleteNode(Node* &root,int x){
    //base case
    if(root==NULL){
        return;
    }
    //if root->data==x  then 3 cases can be seen
    if(root->data==x){
        //0child i.e root is the last node with no childs
        if(root->left==NULL && root->right==NULL){
            delete root;  //just delete the root and return NULL
            return NULL;
        }
    //1child  i.e that root has child on one of its side
        if(root->left!=NULL  && root->right==NULL){
            Node* temp=root->left;  //storing its left childs before deleting so it can be linked again
            delete root;
            return temp;
        }
        if(root->left==NULL  && root->right!=NULL){
            Node* temp=root->right;   //storing its right childs before deleting so it can be linked again
            delete root;
            return temp;
        }
    //2child  i.e that root has child on either side
        if(root->left!=NULL && root->right!=NULL){
            int mini=minimum(root->right);  //finding the min value form its right side , we do it so that assigning it to the root will satisfy the condn of BST(root.data>left && root.data<right)
            root->data=mini;  //assigning that min value to our root 
            root->right=deleteNode(root->right,mini);  //and finally deleting that node from right subtree which had the min value
            return root;

        //or you can use max value from left side of tree and delete that node in left sub tree
            // int maxi=maximum(root->left); 
            // root->data=maxi;  
            // root->left=deleteNode(root->left,maxi);  
            // return root;
        }
    }

    //root->data>x
    if(root->data>x){
        root->left=deleteNode(root->left,x); //go to left of root to find root=x
    }
    //root->data<x
    if(root->data<x){
        root->right=deleteNode(root->right,x); //go to right of root to find root=x
    }
}

int main(){
    Node* root=NULL;
    takeinput(root);
    leveltra(root);
}