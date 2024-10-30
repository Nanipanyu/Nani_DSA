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
void flatten(Node *root)  //we are flattening in preorder order
    {
        //code here
	Node *current, *pre; // current to keep track of root and pre  to traverse in rights of root->left

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) {

		if (current->left == NULL) {  // if current has reached an end in left move current ot right, for following in order
			current = current->right;  //here we are first travelling left then we are travelling to subtrees of left nodes from bottom node
			//if the right does not exist(left not exist too) it means we have reached end of tree so it will get put of loop
		}
		else {

			/* Find the inorder predecessor of current */
			pre = current->left;  // Going to curr left and then its right family to create a link of right family with curr->right to join the curr right as linked list
			while (pre->right != NULL){
				pre = pre->right;
				}

			if (pre->right == NULL) { //if pre/right family has reached Null ,link it with current->right and move current to left
				pre->right = current->right;
				current->right=current->left; //break curr right and bring right to its left  so as to have a ll chain
				current->left=NULL;
				current = current->right;
			}

		} 
	}
    }