#include<iostream>
#include<stack>
#include<vector>
using namespace std;    

//https://www.geeksforgeeks.org/problems/postorder-traversal-iterative/1

struct Node {
    int data;
    Node* left;
    Node* right;
};
class Solution {
  public:
    vector<int> postOrder(Node* node) {
        // code here
        stack<Node*> s;
        vector<int> ans;
        Node* lastvisited = NULL;
        Node* curr = node;
        while(!s.empty() || curr){
            if(curr){                                                      //if current node is not NULL, push it onto the stack and move to its left child(till the leftmost node)
              s.push(curr);
              curr=curr->left;
            }
            else{
                Node* peeknode = s.top();                                   // peek the top node of the stack
                if(peeknode->right && peeknode->right!=lastvisited){        //if top node has a right child(we must visit it before the top node), move to the right child , visited node check is to avoid visiting the right childs again
                    curr=peeknode->right;                                   //traverse the right childs
                }
                else{
                    ans.push_back(peeknode->data);                          //if the top node has no right child or the right child has already been visited, pop the top node and add its data to the result
                    lastvisited=peeknode;
                    s.pop();
                }
            }
        }
        return ans;
    }
};