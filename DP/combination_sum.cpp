#include <bits/stdc++.h> 
using namespace std;

// Problem statement
// You are given an array of distinct integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number tar.
// If N = 3 and tar = 5 and array elements are [1,2,5] then the number of possible ways of making sum = 5 are:
// (1,1,1,1,1)
// (1,1,1,2)
// (1,2,1,1)
// (2,1,1,1)
// (1,1,2,1)
// (2,2,1)
// (1,2,2)
// (2,1,2)
// (5)
//https://www.naukri.com/code360/problems/number-of-ways_3755252?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

int solve(vector<int> &num , int tar ,vector<int> comb,vector<int> &dp){
    if(tar==0){
        return 1;
    }
    if(tar<0){
        return 0;
    }
    if(dp[tar]!=-1){
        return dp[tar];
    }
    int ans=0;
    for(int i=0;i<num.size();i++){
        comb.push_back(num[i]);
        ans += solve(num,tar-num[i],comb,dp);
        comb.pop_back();
    }
    dp[tar]=ans;
    return dp[tar];
}

int solvetab(vector<int> &num , int tar){
    vector<int> dp(tar+1,0);
    dp[0]=1;  // no of comb when target =1 (using num values)
    for(int i=1;i<=tar;i++){  //for no of comb when target =i (using num values)
        for(int j=0;j<num.size();j++){ //iterate over each num value in num array
            if(i-num[j]>=0){
                dp[i] += dp[i-num[j]]; //reduce the targe after using num[j] value, in combination
            }
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    vector<int> comb;
    vector<int> dp(tar+1,-1);
    int ans = solve(num,tar,comb,dp);
    return ans;
}