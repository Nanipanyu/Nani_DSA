#include <bits/stdc++.h>
using namespace std;


class tNode {
	public:
		int data;
		tNode* left;
		tNode* right;
		
		tNode(int data)
	{
		// struct tNode* node = new tNode;
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

/* Function to traverse the binary tree without recursion
and without stack */

//Morris traversal helps in traversing tree in an iterative way with no extra space but only for printing nodes and not for converting tree -> linked list(linking in inorder order)
void MorrisTraversal(struct tNode* root) //for inorder
{
	tNode *current, *pre; // current to keep track of root and pre  to traverse in rights of root

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) {

		if (current->left == NULL) {  // if current has reached an end in left print it( inorder) amd move current ot right
			cout << current->data << " ";
			current = current->right;
		}
		else {

			/* Find the inorder predecessor of current */
			pre = current->left;  // Going to curr left and then its right family to create a link of right family with curr
			while (pre->right != NULL
				&& pre->right != current)
				pre = pre->right;

			/* Make current as the right child of its
			inorder predecessor */
			if (pre->right == NULL) { //if pre/right family has reached Null link it with current and move current to left
				pre->right = current;
				current = current->left;
			}

			/* Revert the changes made in the 'if' part to
			restore the original tree i.e., fix the right
			child of predecessor */
			else if(pre->right == current) {  //if the right family has already been linked(i.e it has been traversed before) break the link of right end with curr nad make it NULL
				pre->right = NULL;
				cout << current->data << " ";
				current = current->right;
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */
}


/* Driver program to test above functions*/
int main()
{
	/* Constructed binary tree is
			1
		/ \
		2	 3
	/ \
	4	 5
*/
	tNode* root = new tNode(1);
	root->left = new tNode(2);
	root->right = new tNode(3);
	root->left->left = new tNode(4);
	root->left->right = new tNode(5);

	MorrisTraversal(root);

	return 0;
}

