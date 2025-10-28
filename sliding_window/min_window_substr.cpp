#include<iostream>
#include<vector>    
#include<unordered_map>   
#include<climits> 
using namespace std;

// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int l=0;
        int r=0;
        int mini=INT_MAX; // to store the length of the minimum window substring
        int start=-1; // to store the starting index of the minimum window substring
        int count=0; //tocheck if all characters of t are present in the current window
        int trgt=t.size();
        for(auto i:t){ // store the frequency of characters in t in map
            mp[i]++;
        }
        if(trgt>s.size()){
            return "";
        }
        while(r<s.size()){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>0){ // if character is present in t(i.e map) and its frequency is greater than 0, we can include it in the current window, by increasing count & decreasing its frequency in map
                    count++;
                }
                mp[s[r]]--;
            }
            while(count==trgt){ // if count equals the size of t, it means we have all characters of t in the current window
                if((r-l+1)<mini){ // check if the current window is smaller than the previous minimum window
                    start=l;   //if yes then update the starting index
                    mini=(r-l+1);  // and update the minimum length to the current window size
                }
                if (mp.find(s[l]) != mp.end()) {
                    mp[s[l]]++;             // we need to shrink the window from the left side, so we increase the frequency of the character at index l in map
                    if (mp[s[l]] > 0) {   // if the frequency of the character at index l becomes greater than 0, it means we have removed one occurrence of a character from the window that was needed to satisfy the condition, so we decrease count
                        count--;
                    }
                }
                l++;
            }
            r++;
        }
        return mini == INT_MAX ? "" : s.substr(start, mini);;
    }
};

// T.C : O(m)+O(2N)