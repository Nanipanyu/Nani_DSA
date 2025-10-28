#include<iostream>
#include<vector>
using namespace std;

// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0; // s and e are used for the first occurrence search
        int e = nums.size() - 1;
        int l = 0;  // l and r are used for the last occurrence search
        int r = e;
        int mid = 0;
        int center = 0;
        bool check=false;
        vector<int> ans(2,-1);           
        while (s <= e || l<=r)
        {   
            mid = s + (e-s) / 2;
            center = l + (r-l) / 2;
            if (s <= e && target > nums[mid])
            {
                s=mid+1;
            }
            if(s <= e && target <= nums[mid])
            {
                if(target==nums[mid]){ //either way if target is not in the array, mid and center will be changing(so we wont know if to return [-1,-1]), but to make sure target is in the array, we check if mid is equal to target
                    check=true;
                }
                e = mid - 1;
            }
            if(l<=r && target>=nums[center]){
                l = center+1;
            }
            if(l<=r && target<nums[center])
            {
                r = center-1;
            }
        }
        if(check){
            ans[0]=s;
            ans[1]=r;
        }
        return ans;
    }
};