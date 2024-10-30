#include<iostream>
#include<queue>
#include<map>
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
void burn(node* root,map<node*,node*> &parent,int target,int &count){
        if(root==NULL){
            return;
        }
        node* targetnode=root;
        if(targetnode->data==target){ //when target node is found from where we need to start to burn
            map<node*,bool> visited;  //visited map so that we can track which node is burned
            queue<node*> q;   //we will  push the attached nodes for a given node in the queue following some conditions
            q.push(targetnode);  //push the target node
            visited[targetnode]=true;  //mark it has been visited
            bool check=false;      //to check if element has been added to the queue or no,i.e if a certain node has unburn neighbour node it will bw added to queue that means bool=true , 1 sec is taken 
            while(!q.empty()){
                int size=q.size();
                for(int i=0;i<size;i++){  //let each neighbour of a node has one of its own neighbour, so when the neighbours catches fire, their(neighbours) neighbour catches fire at all same time, so collectively they take 1 sec, so for loop iused,not to individually go into every branch
                    node*front=q.front();
                    q.pop(); //pop node which has burnt 

                    //here are condition for burning the neighbours
                    if(visited[front->left]!=true && front->left!=NULL){ //if its left is not burnt and is not null
                        q.push(front->left);
                        visited[front->left]=true;  //mark it burn
                        check=true;    //means something has burned so 1sec is taken
                    }
                    if(visited[front->right]!=true && front->right!=NULL){//if its right is not burnt and is not null
                        q.push(front->right);
                        visited[front->right]=true;  //mark it burn
                        check=true;
                    }
                    if(visited[parent[front]]!=true  && parent[front]!=NULL){ //if its parent is not burnt and is not null
                        q.push(parent[front]);
                        visited[parent[front]]=true;  //mark it burn
                        check=true;
                    }
                }
                if(check){  // if its neighbours were burned inc time
                    count++;
                }
                check=false;
            }
        }
        burn(root->left,parent,target,count);
        burn(root->right,parent,target,count);
    }
    void traverse(node* root,map<node* , node*>&parent,node* temp){ //maping nodes with their parent
        if(root==NULL){
            return;
        }
        parent[root]=temp;
        temp=root;
        traverse(root->left,parent,root);
        traverse(root->right,parent,root);
    }
    
    int minTime(node* root, int target) //to  find the minimum time to burn the tree, takes 1second to burn a node and all its attached nodes

    {
        // Your code goes here
        map<node*,node*> parent; //we can keep track of its left and right child, but nots it parent so we map the nodes with their respective parent
        parent[root]=NULL; //for root node its parent is always NULL
        traverse(root,parent,NULL);  //to map parent
        int count=0;
        burn(root,parent,target,count); //counting minimum cost to burn a tree
        return count;
    }

int main(){
    node* root=NULL;
    buildfromlevelorder(root);
    int cost=minTime(root,8);
    cout<<"cost is"<<cost;
    // 1 2 3 4 5 -1 6 -1 -1 7 8 9 10 -1 -1 11 -1 12 -1 -1 -1 -1 -1 -1 13 -1 -1
}