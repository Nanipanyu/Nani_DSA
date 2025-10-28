#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
using namespace std;
  //https://leetcode.com/problems/word-ladder/description/
  //Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

//BFS approach , BFS helps in finding the shortest path in an unweighted graph
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(),wordList.end());                             //inserting all the words into a set for O(1) access
        if(dict.find(endWord)==dict.end()) return 0;
        queue<pair<string,int>> q;                                                               //pair of current word and number of steps taken to reach that word
        q.push({beginWord,1});
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            string word = current.first;
            int steps = current.second;
            if(word==endWord) return steps;                                                       //if we have reached the end word return the number of steps
            for(int i = 0;i<word.size();i++){                                                     //changing each character of the word one by one and checking if the new word is in the set
                string temp = word;
                for(char c = 'a';c <= 'z';c++){
                    temp[i]=c;
                    if(dict.find(temp)!=dict.end()){                                              //if the new word is in the set
                        q.push({temp,steps+1});                                                   //push the new word and increment the steps by 1
                        dict.erase(temp);                                                         //remove the new word from the set so that we don't visit it again && dont worry about the beginWord it was never in the set
                    }
                }
            }
        }
        return 0;
    }
};