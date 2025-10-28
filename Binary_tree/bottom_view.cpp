#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans;

        // Map to store the first node encountered at each horizontal distance.
        // Key: Horizontal Distance, Value: Node's Data
        map<int,int> posn;

        // Queue for level-order traversal. Stores pairs of {Node*, Horizontal Distance}.

        queue<pair<Node*,int>> q;
        if(!root){
            return ans;
        }

        // Start with the root node at horizontal distance 0.
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int> current = q.front();
            Node *temp = current.first;
            int hd = current.second;
            q.pop();

            // keep pushing the current node's data to the map, as going in level order down the bottom.
            posn[hd]=temp->data;
            
            // Enqueue left child with a horizontal distance of hd - 1.
            if(temp->left){
               q.push({temp->left,hd-1});
            }
            
            // Enqueue right child with a horizontal distance of hd + 1.
            if(temp->right){
                q.push({temp->right,hd+1});
            }
        }

        // The map stores keys (horizontal distances) in sorted order.
        // Iterate through the map and add the node values to the result vector.
        for(auto const& pair : posn){
            ans.push_back(pair.second);
        }
        return ans;
    }
};