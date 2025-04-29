#include<iostream>
#include <bits/stdc++.h>
#include<climits>
using namespace std;

//Given a number n, find the minimum number of perfect squares (square of an integer) that sum up to n
//Input: n = 6
// Output: 3
// Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6 
//https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1

class Solution {
    public:
    
      int count(int n ,int up ,vector<int> &dp){
          if(n<0){
              return INT_MAX;
          }
          if(n==0){ //base case, if n is 0, summation completed, we can return 0 as the answer.
              return 0;
          }
          if(dp[n]!=-1){
              return dp[n];
          }
          int ans = INT_MAX; //initialize ans to maximum value, because we need minimum number of squares.
          for(int i=up;i>0;i--){ //we will start from the largest square number(less than n) and go down to 1, so we can get the minimum number of squares.
              int step=count(n-pow(i,2),floor(sqrt(n-pow(i,2))),dp);//we will check for the next number after subtracting the current square number(i) from n, and we will send the square root of the remaining number(n-pow(i,2)) as the next upper limit.
              if(step!=INT_MAX){
                  ans=min(ans,step);//we will take the minimum possible subsequence of the current step(current number n) and move to next possible subsequence.
              }
          }
          dp[n]=ans+1;
          return dp[n];
      }
      
      int MinSquares(int n) {
          vector<int> dp(n+1,-1);
          double root=sqrt(n);
          if(root==floor(root)){ //check if n is a perfect square, if it is, we can return 1 as the answer.
              return 1;
          }
          int up = floor(root); // largest integer less than or equal to the square root of n.
          int ans=count(n,up,dp);
          return ans;
      }
  };