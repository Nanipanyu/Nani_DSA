#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// Given a string s, find the length of the longest substring without repeating characters.
//Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int maxlength=0;
        for(int r=0;r<n;r++){
            for(int j=l;j<r;j++){
                if(s[r]==s[j]){
                    l=j+1;
                }
            }
            maxlength=max(maxlength,(r-l+1));
        }
        return maxlength;
    }
};

//optimized T.C = O(n), 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, maxLength = 0;

        for (int r = 0; r < s.length(); r++) {
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;     // store/overwrite the latest index of s[r]
            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};