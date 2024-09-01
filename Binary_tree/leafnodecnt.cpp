#include <iostream>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void traversal(BinaryTreeNode *root, int &cnt) //inorder method
{
    if (root == NULL)  //base  case
    {
        return;
    }
    traversal(root->left, cnt);
    traversal(root->right, cnt);
    if (root->left == NULL && root->right == NULL)  // leaf node condition
    {
        cnt++;
    }
}

int noOfLeafNodes(BinaryTreeNode *root)
{
    // Write your code here.
    int cnt = 0;
    traversal(root, cnt); //for traversing in btree
    return cnt;
}