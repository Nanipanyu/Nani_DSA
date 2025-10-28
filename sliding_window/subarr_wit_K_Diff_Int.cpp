#include<iostream>
#include<vector>  
#include<unordered_map>      
using namespace std;

class Solution {
public:

    int count(vector<int>& nums, int goal){ 
        int l=0;
        int r=0;
        unordered_map<int,int> mp;
        int ans=0;
        if(goal<0){
            return 0;
        }
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>goal){ // if the number of distinct integers in the current window exceeds goal/k , we need to shrink the window from the left side.
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans=ans+(r-l+1); // here (r-l+1) gives us the count of subarrays ending at r with <=k distinct integers
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int greaterans = count(nums,k); // count of subarrays with  <= k distinct integers
        int smallerans = count(nums,k-1);// count of subarrays with <= (k-1) distinct integers
        return (greaterans-smallerans); // the difference gives us the count of subarrays with exactly k distinct integers
    }
};