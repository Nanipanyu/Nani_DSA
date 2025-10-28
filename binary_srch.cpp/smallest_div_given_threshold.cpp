#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
// This problem is about finding the smallest divisor such that the sum of the division of each element in the array by the divisor is less than or equal to a given threshold.

class Solution {
public:

    bool underlimit(vector<int>& nums, int &threshold, int &divisor){
        int sum = 0;
        for(int val : nums){
            sum += (val + divisor - 1) / divisor;
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int mid = low + (high-low)/2;
        int result = high;

        while(low<=high){
            if(underlimit(nums,threshold,mid)){
                result=mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            mid =  low + (high-low)/2;
        }  
        return result;      
    }
};