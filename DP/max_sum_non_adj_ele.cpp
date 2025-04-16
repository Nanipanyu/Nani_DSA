#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int maximise(vector<int> &nums,int start,vector<int> &dp){
    if(start>=nums.size()){ //when we excedd the size of nums 
        return 0;
    }
    if(dp[start]!=-1){
        return dp[start];
    }
    int maxi=0;
    for(int i=0;i<2;i++){ //check for the current element and the next elements combination as both together cant be taken
        int ans1 = maximise(nums,start+i+2,dp);
        int ans2 = maximise(nums,start+i+3,dp);
        maxi = max(maxi,nums[start+i]+max(ans1,ans2)); //Out of the two adjacent options, we will take the one with max sum
        dp[start+i] = max(ans1,ans2) + nums[start+i];
    }
    return maxi;
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size()+1,-1); //memoization
    int ans = maximise(nums,0,dp);
    return ans;
}



///Method-2

int maximise(vector<int> &nums, int start, vector<int> &dp) {
    if (start >= nums.size()) return 0;

    if (dp[start] != -1){
        return dp[start];
    }
    // Option 1: Pick the current element and move to start+2
    int pick = nums[start] + maximise(nums, start + 2, dp);
    
    // Option 2: Skip the current element and move to start+1, here we dont have 'nums[start] +' because we are skipping the current element and the addition will be done in the next recursive call in abpve line
    int notPick = maximise(nums, start + 1, dp);

    // Store the result in dp[start]
    return dp[start] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    vector<int> dp(nums.size(), -1); // Memoization
    return maximise(nums, 0, dp);
}