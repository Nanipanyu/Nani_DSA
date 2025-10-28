#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// This problem is about finding the minimum capacity of a ship such that it can ship all packages within a given number of days.

class Solution {
public:
    bool canship(vector<int>& weights, int days,int capacity){
        int load=0;
        int time = 1;
        for(int w:weights){
            if(w>capacity)return false;       // If a single package exceeds the capacity, it's impossible to ship it
            if(load+w>capacity){               // If the current load plus the new package exceeds the capacity,then we need to shipthe current package on a new day
                time++;                        // Increment the day count(for shipping)
                load=w;
            }
            else{
                load+=w;
            }
        }
        return time<=days;

    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int high = 0;
        for (int weight:weights){
            high=high+weight;                                           // Sum of all weights is the maximum capacity needed
        }
        int low = *max_element(weights.begin(),weights.end());          // The minimum capacity needed is the maximum weight of a single package
        int mid = low + (high-low)/2;
        int result=high;

        while(low<=high){
            if(canship(weights,days,mid)){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            mid=low+(high-low)/2;
        }
        return result;
    }
};