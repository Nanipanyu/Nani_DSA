#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Given an integer array nums, find the contiguous(continuous) subarray (containing at least one number) which has the largest sum and return its sum.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l=0;
        int r=0;
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum < 0) sum=0;
        }
        return ans;

    }
};