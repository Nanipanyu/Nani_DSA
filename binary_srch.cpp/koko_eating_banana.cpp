#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:

    bool caneatall(vector<int>& piles, int k, int h){  // Function to check if Koko can eat all bananas at speed k within h hours 
        long long totalhrs=0;
        for(int pile : piles){
            totalhrs += (pile + k - 1) / k; //ceil(pile / k)    counting the hours needed to eat each pile if Koko eats at speed k
        }
        return totalhrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int result = high;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(caneatall(piles,mid,h)){  // If Koko can eat all bananas at speed mid within h hours
                result = mid;
                high = mid-1;  // Try to find a smaller speed
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};