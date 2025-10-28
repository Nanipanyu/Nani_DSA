
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
//For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
//The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

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
    // This function is fine, it correctly gathers the nodes and their coordinates.
    void trace(TreeNode* root, vector<pair<int, pair<int, int>>>& p, int r, int c) {
        if (!root) {
            return;
        }
        auto ptemp = make_pair(r, c);
        p.push_back(make_pair(root->val, ptemp));
        trace(root->left, p, r + 1, c - 1);
        trace(root->right, p, r + 1, c + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // vector of {value, {row, column}}
        vector<pair<int, pair<int, int>>> p;
        trace(root, p, 0, 0);

        // This single sort call replaces all your custom sorting functions.
        // It provides the correct sorting logic in one pass.
        sort(p.begin(), p.end(), [](const auto& a, const auto& b) {
            // Rule 1: If columns are different, sort by column.
            if (a.second.second != b.second.second) {
                return a.second.second < b.second.second;
            }
            // Rule 2: If columns are the same, sort by row.
            if (a.second.first != b.second.first) {
                return a.second.first < b.second.first;
            }
            // Rule 3: If row and column are also the same, sort by value.
            return a.first < b.first;
        });

        vector<vector<int>> finalans;
        if (p.empty()) {
            return finalans;
        }

        // This grouping logic now works perfectly because 'p' is correctly sorted.
        vector<int> tempo;
        // Start with the first node's column
        int currentCol = p[0].second.second;

        for (const auto& node : p) {
            if (node.second.second != currentCol) {
                // A new column is detected, so push the completed old column
                finalans.push_back(tempo);
                // And start a new list for the new column
                tempo.clear();
                currentCol = node.second.second;
            }
            tempo.push_back(node.first);
        }
        // Don't forget to add the very last column after the loop finishes
        finalans.push_back(tempo);

        return finalans;
    }
};