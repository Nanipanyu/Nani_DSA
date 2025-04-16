#include <bits/stdc++.h> 
#include <vector>
using namespace std;


long long int maximise(vector<int> &nums, int start, vector<int> &dp) {
    if (start >= nums.size()) return 0;

    if (dp[start] != -1){
        return dp[start];
    }
    // Option 1: Pick the current element and move to start+2
    long long int pick = nums[start] + maximise(nums, start + 2, dp);
    
    // Option 2: Skip the current element and move to start+1
    long long int notPick = maximise(nums, start + 1, dp);

    // Store the result in dp[start]
    return dp[start] = max(pick, notPick);
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    vector<int> first, second;
    for(int i=0;i<n;i++){  //We will divide the houses into two parts, one including the 1sthouse and excluding the last house and other including the lasthouse and excluding the first house
        if(i!=0){
            first.push_back(valueInHouse[i]);
        }
        if(i!=n-1){
            second.push_back(valueInHouse[i]);
        }
    }
    vector<int> dpfirst(first.size() , -1);
    vector<int> dpsecond(second.size() , -1);
    if(n==1){
        return valueInHouse[0];
    }
    return max(maximise(first, 0, dpfirst),maximise(second, 0, dpsecond));
}