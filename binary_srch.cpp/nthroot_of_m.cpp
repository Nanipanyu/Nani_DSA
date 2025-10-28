#include<iostream>
#include<cmath>
using namespace std;

class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int s=1;
        int e=m;
        int mid=s+(e-s)/2;
        if(n==1){
            return m;
        }
        
        while(s<=e){
            if(m == pow(mid,n)){
                return mid;
            }
            if(m > pow(mid,n)){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
};