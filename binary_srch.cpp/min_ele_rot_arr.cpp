#include<iostream>
#include<vector>
using namespace std;

// Given a rotated sorted array, find the minimum element in it.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        int mid = s + (e - s) / 2;

        while (s < e) {
            // Left half is sorted
            if (nums[s] <= nums[mid]) { // If left half is sorted, then 2 case because left half can be sorted in a rotated way or in a normal way
                if (nums[mid] > nums[e]) { // left half is sorted in a rotated way, then smallest element will be in right side of mid
                    s = mid + 1;
                } else {                   // left half is sorted in a normal way, then smallest element will be in left side of mid or mid itself
                    e = mid ;
                }
            }
            // Right half is sorted
            else {
                e=mid; //if right half is sorted, then only one case possible, that is samllest element is in mid or left side of mid
            }
            mid = s + (e - s) / 2;
        }
        return nums[mid];
    }
};