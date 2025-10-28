#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//Given a string s consisting only of characters a, b and c.Return the number of substrings containing at least one occurrence of all these characters a, b and c.
//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

//Approach1: 
class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int r=0;
        int ans=0;
        int e=s.size();
        unordered_map<char,int>mp;
        while(r<s.size()){
            mp[s[r]]++;
            if(mp.size()==3){
                while(mp.size()==3){
                    ans=ans+e-r; //if in map all 3(a,b,c)are present , then (e-r)=all the substrings starting from r to e will satisfy the condition
                    mp[s[l]]--;
                    if(mp[s[l]]==0){
                        mp.erase(s[l]);
                    }
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};
//In Approach1 the problem was inner while loop:T.C:O(n^2), once the condition is satisfied,we had to shrink the window from left side, which took O(n) time in worst case.


//Approach2: T.C(O(n))
class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int r=0;
        int ans=0;
        int e=s.size();
        vector<int> db(3,-1);
        while(r<s.size()){
           db[s[r]-'a']=r; //last seen index of character a,b,c
           if(db[0]!=-1 && db[1]!=-1 && db[2]!=-1){
                ans=ans+min(min(db[0],db[1]),db[2])+1; //here when all three characters are present, we find the minimun window from the right side(where condition is satisfied) to the left side, which replaces the inner while loop in Approach1.here min(db[0],db[1],db[2]) gives the leftmost index among the three characters, to find the smallest window that contains all three characters.
           }
           r++;
        }
        return ans;
    }
};