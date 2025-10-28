#include<iostream>
#include<vector>
using namespace std;

// Given a sorted array nums consisting of only integers where every element appears exactly twice except for one element which appears exactly once. Find this single element that appears only once.

//the approch here is before the single element each ele first appears at even index and the next one at odd index. Ex: nums: [1,1,2,2,3,3,4,5,5] 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        while(s<e){
            int mid = s+(e-s)/2;

            if(mid%2 == 1)mid--; // to make sure mid is even, so that we can check the next element

            if(nums[mid]==nums[mid+1]){ // if mid and mid+1 are same, it means the single element is after mid in right side
                s=mid+2;
            }
            else{
                e=mid; // if mid and mid+1 are not same, it means the single element is at mid or before mid in left side
            }
        }
        return nums[s];
    }
};