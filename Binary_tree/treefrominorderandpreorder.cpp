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

int findposition(int in[],int ele,int n) //to find the position of (pre array value) in inorder array
    {
        for(int i=0;i<n;i++){
            if(in[i]==ele){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int n,int &index,int instart,int inend)
    {
        if(index>=n || instart>inend){ //while traversing in pre array if index>=n , and instart is the start of inorder array and inend is the end of inorder array,they are updated corresponding to elements in pre array
            return NULL;
        }
        int ele=pre[index++];  //traverse through pre array
        int pos=findposition(in,ele,n);  //find position of ele  in inorder array
        Node* temp=new Node(ele);
        temp->left=solve(in,pre,n,index,instart,pos-1); //Attach the left side of inorder array to the left of ele(make the inend= its posn -1)
        temp->right=solve(in,pre,n,index,pos+1,inend); //Atach the right side of inorder array to the right of ele(make the instart=its posn +1)
        return temp;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preindex=0; //index of pre array
        Node* ans=solve(in,pre,n,preindex,0,n-1);
        return ans;
        
    }

    int main(){
        int in[] = {3,1,4,0,5,2};
        int pre[] = {0,1,3,4,2,5};
        Node* root=NULL;
        root=buildTree(in,pre,6);
    }