#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:

    int dfs(TreeNode* node, int &start,int &maxTime) {
        // Base case: an empty node has a depth of 0.
        if (node == nullptr) {
            return 0;
        }

        // Recursively search in left and right subtrees.
        int leftDepth = dfs(node->left, start,maxTime);
        int rightDepth = dfs(node->right, start,maxTime);

        // Case 1: The current node is the start of the infection.
        if (node->val == start) {
            // The time to infect its own subtrees is their depth.
            maxTime = max(leftDepth, rightDepth);
            // Return -1 to signal to parent nodes that the start was found. and also to account for the time taken to infect its other parts by using abs(value)
            return -1;
        }

        // Case 2: The start node is NOT in this subtree.
        // Both depths will be positive.
        if (leftDepth >= 0 && rightDepth >= 0) {
            // Return the normal depth of this subtree.
            return 1 + max(leftDepth, rightDepth);
        }
        
        // Case 3: The start node is in one of the subtrees.
        // One of the depths will be negative.
        else {
            // The total distance is the path from the start node up to this node, 
            // and then down the other branch.
            int distance = abs(leftDepth) + abs(rightDepth);                       // Calculate the distance for the longest subtree of the current node(i.e above infected node) from the infected/start node to the other side of current
            maxTime = max(maxTime, distance);
            
            // Pass the distance to the parent nodes from the infected/start node , incrementing it by 1(because its abs value will be used).
            return min(leftDepth, rightDepth) - 1;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        int maxTime = 0;
        dfs(root, start,maxTime);
        return maxTime;
    }
};