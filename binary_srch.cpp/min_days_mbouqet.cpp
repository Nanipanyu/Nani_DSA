#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
// This problem is about finding the minimum number of days required to make m bouquets of k flowers each, given the bloom days of flowers.

class Solution {
public:
    bool canboquet(vector<int>& bloomDay, int &m, int &k, int &day){
        int flowers = 0; // Count of consecutive flowers that can bloom by day(mid)
        int bouqet = 0;  // Count of bouquets made
        for(int d:bloomDay){
            if(d <= day){
                flowers++;                  // If the flower blooms by day(mid), increase the count of consecutive flowers
                if(flowers==k){             // If we have k consecutive flowers, we can make a bouquet
                    bouqet++;
                    flowers=0;              // Reset the count of consecutive flowers after making a bouquet, because each flower can be used only  in exactly one bouquet.
                }
            }
            else{
                flowers=0;                   // If the flower does not bloom by day(mid) i.e not consecutive, reset the count of consecutive flowers
            }
        }
        return bouqet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;
        int mid = low + (high-low)/2;  // Calculate the mid value for binary search i.e a mid day to check if we can make the bouquets by that day
        long long totalflowerneeded = 1LL*m*k;

        if(totalflowerneeded > bloomDay.size()){ // If the total number of flowers needed is more than available, return -1
            return -1;
        }
        while(low<=high){
            if(canboquet(bloomDay,m,k,mid)){ // If we can make m bouquets with k flowers each by day mid
                result = mid;
                high=mid-1;                  // Try to find a smaller day
            }
            else{   // If we cannot make m bouquets by day mid, we need to increase the day
                low=mid+1;
            }
            mid = low + (high-low)/2;
        }  
        return result;      
    }
};