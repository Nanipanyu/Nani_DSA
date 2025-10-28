#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// This code is a solution to the "Allocate Minimum Number of Pages" problem, which involves distributing books to students such that the maximum number of pages assigned to a student is minimized.

class Solution {
  public:
  
    bool ispossible(vector<int> &arr, int k, int trialpage){
        int students = 1;
        int pages = 0;
        for(int page:arr){
            if(pages+page > trialpage){                        // If the current number of pages plus the new book exceeds the trial page limit
                students++;                                    // Increment the student count
                pages=page;                                    // Assign the current book to the new student                    
            }
            else{
                pages+=page;
            }
        }
        return students<=k ;                                    // If the number of students needed is less than or equal to k, then the trial page limit is possible, and we might need to try a smaller limit
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int high = 0;
        for (int val:arr){
            high=high+val;                                           // Sum of all weights is the maximum capacity needed
        }
        int low = *max_element(arr.begin(),arr.end());               // The smallest possible maximum number of pages assigned to a student is the maximum number pages single book
        int mid = low+(high-low)/2;                                  // mid is the manimum trial number of pages we are checking to allocate to students
        int result = -1;
        if(k>arr.size()){                                            // If the number of students is greater than the number of books, it's impossible to allocate pages
            return -1;
        }
        while(low<=high){
            if(ispossible(arr,k,mid)){
                high=mid-1;
                result = mid;
            }
            else{
                low=mid+1;
            }
            mid=low+(high-low)/2 ;
        }
        return result;
    }
};