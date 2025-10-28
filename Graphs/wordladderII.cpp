#include <iostream>
#include <unordered_set>
#include <vector>   
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
 //https://leetcode.com/problems/word-ladder-ii/
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation   

class Solution {
public:
    void fillwithdfs(vector<vector<string>> &ans,string &endWord,unordered_map<string,vector<string>> &parent,vector<string> store,
    string beginWord){
        if(endWord == beginWord){
            reverse(store.begin(), store.end());                                         //reversing the store to get the path from beginWord to endWord
            ans.push_back(store);
            reverse(store.begin(), store.end());                                         //reversing the store back to its original form
            return;
        }
        for(auto j : parent[endWord]){
            store.push_back(j);                                                           //storing the current word
            fillwithdfs(ans,j,parent,store,beginWord);                                     //backtracking to the parent of the current word using dfs
            store.pop_back();                                                             //removing the current parent to explore other parents/ i.e alternate paths
        }  
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());                             //inserting all the words into a set for O(1) access
        vector<vector<string>> ans;
        if(dict.find(endWord)==dict.end()) return ans;                                           //if endWord is not in the set return empty vector, because we can't reach to it
        unordered_set<string> current, next;                                                     //to store the current level and next level words, we are not using queue here because it gives TLE if one word can be transformed by a lot of other availble words causing excessive duplication(leading to same path multiple times in our answer) & we need to erase the whole level at once
        current.insert(beginWord);
        unordered_map<string,vector<string>> parent;                                             //to store the parent of each word, so that we can backtrack to find the all possible path
        bool found = false;                                                                      //to check if we have found the endWord
        while (!current.empty() && !found) {
            for (auto &w : current) dict.erase(w); // mark whole level visited                   //erasing the whole level at once,all neighbours of current level delete at once
            for (auto &word : current) {
                string temp = word;
                for (int i = 0; i < word.size(); i++) {
                    temp = word;
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if (dict.find(temp) != dict.end()) {
                            next.insert(temp);
                            parent[temp].push_back(word);
                            if (temp == endWord) found = true;
                        }
                    }
                }
            }
            swap(current, next);                                                                   //move to the next level
            next.clear();                                                                          //clear the next level for the next iteration
        }
        vector<string> store;
        store.push_back(endWord);                                                                   //pushing the endWord to start backtracking
        fillwithdfs(ans,endWord,parent,store, beginWord);                                           //backtracking to find all the paths
        return ans;
    }
};