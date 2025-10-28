#include <bits/stdc++.h>
using namespace std;

//check if there is a pair with sum k in the BST

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

bool findTarget(Node* root, int k, unordered_set<int>& seen) {
    if (!root) return false;

    // If complement already exists, return true
    if (seen.count(k - root->val)) return true;                                  // Check if the complement exists, if it does, we found a pair

    // Otherwise, store current value
    seen.insert(root->val);

    // Recurse on left and right
    return findTarget(root->left, k, seen) || findTarget(root->right, k, seen);
}

bool findTarget(Node* root, int k) {
    unordered_set<int> seen;
    return findTarget(root, k, seen);
}


