#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/alien-dictionary/1
//Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
// Output: true
// Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
// The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
// The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
// The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
// The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
// So, 'b' → 'd' → 'a' → 'c' is a valid ordering.

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char,int> indegree;
        unordered_set<char> allchars;
        unordered_map<char,vector<char>> adj;
        
        for (auto &w : words) {
            for (auto c : w) {
                allchars.insert(c);
                indegree[c] = 0;  // initialize indegree
            }
        }
        for(int i = 0;i<words.size()-1 ;i++){
            string wrd1 = words[i];
            string wrd2 = words[i+1];
            if (wrd1.size() > wrd2.size() && wrd1.find(wrd2) == 0) {
                return "";
            }

            int size = min(wrd1.size(),wrd2.size());
            for(int j=0;j<size;j++){
                if(wrd1[j]!=wrd2[j]){
                    adj[wrd1[j]].push_back(wrd2[j]);
                    indegree[wrd2[j]]++;
                    break;
                }   
            }
        }
        queue<char> q;
        string ans;
        for(auto k : allchars){
            if(indegree[k]==0){
                q.push(k);
            }
        }
        while(!q.empty()){
            char front = q.front();
            ans.push_back(front);
            q.pop();
            for(auto h:adj[front]){
                indegree[h]--;
                if(indegree[h]==0){
                    q.push(h);
                }
            }
        }
        if(ans.size()!=allchars.size()){
            return "";
        }
        return ans;
    }
};