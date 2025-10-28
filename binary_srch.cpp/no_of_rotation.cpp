#include<ios>tream>
#include<vector>
using namespace std;
// Given a rotated sorted array, find the number of rotations in it.
// Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
// Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
// After 1st Rotation : [9, 2, 4, 6]
// After 2nd Rotation : [6, 9, 2, 4]


class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;
        while(s<e){
            if(arr[mid]>=arr[s]){
                if(arr[mid]>arr[e]){
                    s=mid+1;
                }
                else{
                    e=mid;
                }
                
            }
            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return (mid%(arr.size()));
    }
};