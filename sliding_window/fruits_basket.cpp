#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//Problem: https://leetcode.com/problems/fruit-into-baskets/submissions/1649223768/
//Max no of fruits in two baskets(Each basket can have only one type of fruit), fruits[i] is the type of fruit 

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int r = 0;
        int maxlength=0;
        unordered_map<int, int> mp;
        while(r<fruits.size()){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            maxlength=max(maxlength,(r-l+1));
            r++;
        }
        return maxlength;
    }
};
