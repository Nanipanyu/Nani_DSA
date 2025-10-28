#include<iostream>
#include<vector>        
using namespace std;

// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].


// similar to binary_sub_arr_wit_sum.cpp, 
//Here k=goal, odds=1, evens=0  
class Solution {
public:

int count(vector<int>& nums, int goal){ //this algo is to find the number of subarrays with sum <= goal ;
        int l=0;
        int r=0;
        int sum=0;
        int ans=0;
        if(goal<0){
            return 0;
        }
        while(r<nums.size()){
            sum=sum+(nums[r]%2);//converting odd & even no to 1 & 0 respectively, summing odd 1 will give us the count of odd numbers in the subarray
            while(sum>goal){ 
                sum=sum-nums[l]%2; //con
                l++;
            }
            ans=ans+(r-l+1);
            r++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int greaterans = count(nums,k); 
        int smallerans = count(nums,k-1);
        return (greaterans-smallerans); 
    }
};