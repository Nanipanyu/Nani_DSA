#include<iostream>
#include<vector>        
using namespace std;

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1]
// [1,0,1,0]
// [0,1,0,1]
// [1,0,1]

class Solution {
public:
    //T.C:O(2n)
    int count(vector<int>& nums, int goal){ //this algo is to find the number of subarrays with sum <= goal ;
        int l=0;
        int r=0;
        int sum=0;
        int ans=0;
        if(goal<0){
            return 0;
        }
        while(r<nums.size()){
            sum=sum+nums[r];
            while(sum>goal){ //we cant use use this nested while loop with(if sum==goal logic) because when  sum>goal, and we shrink the window from left side, we might get sum=goal, but not all subarrays will be counted(Try for [1,0,1,0,1]) when last indexis reached and we shrink window from left side, we miss [1,0,1] of the last
                sum=sum-nums[l];
                l++;
            }
            ans=ans+(r-l+1);
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int greaterans = count(nums,goal); 
        int smallerans = count(nums,goal-1);
        return (greaterans-smallerans); //if (sum<=goal)-(sum<=goal-1) we get the sum=goal count;
    }
};

