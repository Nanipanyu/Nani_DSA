#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
 //find the length of the longest substring that can be obtained by replacing at most k characters in the string s with any other character. The substring must consist of only one unique character after replacements.
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int l=0;
        int r=0;
        int maxfreq=0;
        int maxlength=0;
        while(r<s.size()){
            mp[s[r]]++;
            maxfreq=max(maxfreq,mp[s[r]]); //keep track of the maximum frequency of any character in the current window
            if(((r-l+1)-maxfreq)>k){ //if within the window of (r-l) characters, the number of characters that are not the most frequent character exceeds k, we need to shrink the window from the left side. as we can replace at most k characters and that window will not be valid anymore.
                mp[s[l]]--;
                l++;
            }
            maxlength=max(maxlength,(r-l+1));
            r++;
        }
        return maxlength;
    }
};