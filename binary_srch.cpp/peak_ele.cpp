#include<iostream>
#include<vector>
using namespace std;

//A peak element is an element that is strictly greater than its neighbors.
// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s+(e-s)/2;
        
        while(s<e){
            if(nums[mid]>nums[mid+1]){ // if mid is greater than mid+1, means theres a possible peak on the left side or at mid
                e=mid;
            }
            else{   // if mid is less than mid+1, means theres a possible peak on the right side
                s=mid+1;
            }
            mid = s+(e-s)/2;
        }
        return s;
    }
};