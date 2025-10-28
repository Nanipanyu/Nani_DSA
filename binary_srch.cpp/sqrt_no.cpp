#include <iostream>
using namespace std;

// Given a non-negative integer x, return the square root of x rounded down to the nearest integer in log(n). The returned integer should be non-negative as well.


class Solution {
public:
    int mySqrt(int x) {
        int s = 1;
        int e = x;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(mid == x/mid){
                return mid;
            }
            if(mid > x/mid){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return e;
    }
};