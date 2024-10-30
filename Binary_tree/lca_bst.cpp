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
Node *LCAinaBST(Node *root, Node *P, Node *Q)
{
    // Write your code here.
    // Run loop until the condition of lca in bst is satisfied i.e: until root->data is in middle of p->data/Q->data and Q->data/p->data 
    while(!(((root->data)>=(P->data) && (root->data)<=(Q->data)) || ((root->data)>=(Q->data) && (root->data)<=(P->data)))){  
        if((root->data)>(Q->data) && (root->data)>(P->data)){ //root data is greater than both(P and Q) lca is in left, so move left
            root=root->left;
        }
        if ((root->data) < (Q->data) && (root->data) < (P->data)) { //root data is smaller than both(P and Q) lca is in right, so move right
            root = root->right;
        }
    }
    return root;
}