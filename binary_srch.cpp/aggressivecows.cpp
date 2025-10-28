#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://www.geeksforgeeks.org/problems/aggressive-cows/1
// This code is a solution to the "Aggressive Cows" problem, which involves placing k aggressive cows in stalls such that the minimum distance between any two cows is maximized.

class Solution {
  public:
  
    bool ispossible(vector<int> &stalls, int k, int trialdist){
        int lastposn=stalls[0];
        int cows = 1;
        for(int stall:stalls){
            if(stall-lastposn>=trialdist){                    // Check if the current stall is far enough(greater than equal to trialdist)from the last placed cow
                cows++;                                       // if yes Place a cow in the current stall
                if(cows==k){                                  // if all aggressive cows are placed , trial distance is possible
                    return true;
                }
                lastposn=stall;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end()); 
        int m = stalls.back();
        int n = stalls.front();
        int low = 0;
        int high = m-n;                             //maximum distance between the first and last stall 
        int mid  = low+(high-low)/2;                //mid is the trial distance we are checking to place aggressive cows
        int result = -1;
        while(low<=high){
            if(ispossible(stalls,k,mid)){           // if it is possible to place k cows with at least mid distance apart
                result=mid;
                low=mid+1;                          // if trial distance  it is possible, try to increase the minimum distance 
            }
            else{
                high=mid-1;
            }
            mid=low+(high-low)/2;
        }
        return result;
    }
};