#include<iostream>
#include<vector>
using namespace std;


// You are given a sorted array 'arr' of distinct values and a target value 'm'. You need to search for the index of the target value in the array.

// Note:
// 1. If the value is present in the array, return its index.
// 2. If the value is absent, determine the index where it would be inserted in the array while maintaining the sorted order. 
// 3. The given array has distinct integers.
// 4. The given array may be empty.

int searchInsert(vector<int>& arr, int m)
{
	// Write your code here.
	int s=0;
    int e=arr.size()-1;
    int mid=0;
    while(s<=e){
        mid=s+(e-s)/2;
        if(m==arr[mid]){
			return mid;
        }
		if(m>arr[mid]){
			s=mid+1;
		}
        else{
            e=mid-1;
        }
    } 
    return s;
}