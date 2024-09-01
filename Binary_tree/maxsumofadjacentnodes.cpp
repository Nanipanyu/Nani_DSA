#include<iostream>
#include<vector>
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

Node* buildtree(Node* root){
    int data;
    cout<<"Enter the data for the node"<<" "<<endl;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of"<<" "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data for inserting in right of"<<" "<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}

void solve(Node* root,pair<int , int>p, vector<pair<int,int>> v,pair<int , int> &ans){
        if(root==NULL){
            v.push_back(p);
            return;
        }
        v.push_back(p);
        solve(root->left,p,v,ans);
        solve(root->right,p,v,ans);
        v[v.size()-3].first=root->data+v[v.size()-1].second +v[v.size()-2].second;
        v[v.size()-3].second=max(v[v.size()-1].first, v[v.size()-1].second) + max(v[v.size()-2].first,v[v.size()-2].second);
        for(int i=0;i<2;i++){
            v.pop_back();
        }       
        ans=v[0];
    }

    int getMaxSum(Node *root) 
    {
        // Add your code here
        vector<pair<int,int>> v;
        pair<int , int>p=make_pair(0,0);
        pair<int , int>ans;
        solve(root,p,v,ans);
        cout<<"lore"<< " "<<ans.first<<" "<<ans.second<<endl;
        int greatest=max(ans.first,ans.second);
        return greatest;
    }

    int main(){
        Node* root = NULL;
        root = buildtree(root);
        cout << "Max Sum of the path is " <<" "<< getMaxSum(root) << endl;
    }
