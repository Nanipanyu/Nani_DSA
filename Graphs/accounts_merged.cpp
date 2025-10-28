#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
public:

    class Disjointset{
        vector<int> size , parent;
        public:
        Disjointset(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i = 0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findparent(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node] = findparent(parent[node]);
        }
        void unionbysize(int u , int v){
            u = findparent(u);
            v = findparent(v);
            if(u == v) return;
            if(size[u]>size[v]){
                parent[v] = u;
                size[u]+=size[v];
            }
            else{
                parent[u] = v;
                size[v]+=size[u];
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        Disjointset ds(accounts.size());
        unordered_map<string,int> emailtoint;

         // Step 1: Union accounts with common emails
        for(int i = 0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(emailtoint.find(accounts[i][j])==emailtoint.end()){                     // If email is not present in the map
                    emailtoint[accounts[i][j]] = i;                                       // Map email to account index
                }
                else{
                    ds.unionbysize(i,emailtoint[accounts[i][j]]);                           // If email is already present, means the curr acc mails is to be merged,so union the current account with the account index stored in the map 
                }
            }
        }

        // Step 2: Group emails for each ultimate parent account
        unordered_map<int,set<string>> mergedmails;           
        for(auto &it : emailtoint){
            string email = it.first;                                                 // Get the email
            int ultparent = ds.findparent(it.second);                                // Find the ultimate parent account index for this email
            mergedmails[ultparent].insert(email);                                    // Insert email into the set of emails for the ultimate parent account
        }

        // Step 3: Prepare the final merged account list
        vector<vector<string>> ans;
        for(auto &it : mergedmails){
            vector<string> acc;
            acc.push_back(accounts[it.first][0]);                                      //get the name of the account for tha parent it.first
            acc.insert(acc.end(),it.second.begin(),it.second.end());                   // Insert all emails from the set (it.second) into the account vector
            ans.push_back(acc);
        }
        return ans;        
    }
};