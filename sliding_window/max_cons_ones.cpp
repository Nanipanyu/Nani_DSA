#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0 , r=0;
        int maxlength = 0;
        int count=0;
        while(r<nums.size()){
            if(nums[r]==0){
                count++;
            }
            if(count>k){  // if we have more than k zeros, we need to move the left pointer and shrink the window until condition satisfies
                while(count>k){
                    if(nums[l]==0){
                        count--;
                    }
                    l++;
                }
            }
            maxlength=(maxlength,(r-l+1));
            r++;
        }
        return maxlength;
    }
};


//optimal approach O(n)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0 , r=0;
        int maxlength = 0;
        int count=0;
        while(r<nums.size()){
            if(nums[r]==0){
                count++;
            }
            if(count>k){
                if(nums[l]==0){
                    count--;
                }
                l++;
            }
            maxlength=(maxlength,(r-l+1));
            r++;
        }
        return maxlength;
    }
};