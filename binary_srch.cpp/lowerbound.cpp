#include <iostream>
#include <vector>
using namespace std;
// You are given an array 'arr' sorted in non-decreasing order and a number 'x'. You must return the index of the lower bound of 'x'.
// Note:
// 1. For a sorted array 'arr', 'lower_bound' of a number 'x' is defined as the smallest index 'idx' such that the value 'arr[idx]' is not less than 'x'.If all numbers are smaller than 'x', then 'n' should be the 'lower_bound' of 'x', where 'n' is the size of array.


int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int s=0;
    int e=n-1;
    int mid=0;
    while(s<=e){
        mid=(s+(e-s))/2;
        if(x>arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    if(s>=n){
        return n;
    }
    return s;
}
