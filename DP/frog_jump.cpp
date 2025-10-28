#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/frog-jump/
//A frog is crossing a river. The river is divided into x units and at each unit, there is a stone. The frog can jump to the next stone or the stone after that. The goal is to find the maximum distance the frog can jump.

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int ans = 0;
        for (int i = 2; i < n; ++i)                                            
            ans = max(ans, stones[i] - stones[i-2]);                           //checking the max jump by skipping one stone , because stones is sorted, max jump will be between every alternate stone
        if (n >= 2) ans = max(ans, stones[1] - stones[0]);
        if (n >= 2) ans = max(ans, stones[n-1] - stones[n-2]);
        return ans;
    }
};