#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include<climits>
using namespace std;
//https://www.naukri.com/code360/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items(no same items).

//Top down approach
int solve(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp){
	if(index==0){ //base case, if only one item is there, then we can either take it or leave it, or if we have reached the finsl item
		if(weight[index]>capacity){
			return 0;
		}
		else{
			return value[index];
		}
	}
	if(dp[index][capacity]!=-1){
		return dp[index][capacity];
	}
	int include = 0;
    //if we include the current item, we need to check if the weight of the current item is less than or equal to the capacity of the knapsack. If it is, we can include it and updates it current capacity, and go check if the next item can be added.
	if(weight[index]<=capacity){
		include = value[index] + solve(weight,value,index-1,capacity-weight[index],dp);
	}
	int exclude = 0 + solve(weight,value,index-1,capacity,dp); //theres also a case if we exclude the current item, in our possible combination, we just need to check if the next item can be added with the same capacity.
	dp[index][capacity] = max(include,exclude); //we will take the maximum of both cases, [index][capacity] stores you the highest value for current combination and and current capacity(with each combination capacity changes, so we have to mind capacity as well).
	return dp[index][capacity];
}

int spaceoptimized(vector<int> &weight, vector<int> &value, int n, int capacity){
    vector<int> prev(capacity+1,0);
    vector<int> curr(capacity+1,0); //current array to store the maximum value for each capacity at the current index and depends on previosly calculated values.
    for(int i=0;i<=capacity;i++){
        if(weight[0]<=i){ //check if weight[0] can fit in current capacity i
            prev[i] = value[0];
        }
        else{
            prev[i] = 0;
        }
    }
    for(int index=1;index<n;index++){
        for(int w=0;w<=capacity;w++){
            int include = 0;
            if(weight[index]<=w){ //check if the current item can be included in the knapsack, by check for different capacity values
                include = value[index] + prev[w-weight[index]];//if it can be included, we add its value(value[index]) to the maximum value of the remaining capacity (w-weight[index]).
            }
            int exclude = 0 + prev[w]; 
            curr[w] = max(include,exclude);
        }
        prev = curr; //update the previous array with the current array after each iteration.
    }
    return prev[capacity];
}

//Bottom up approach
int solvetabulation(vector<int> &weight, vector<int> &value, int n, int capacity){
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    for(int i=0;i<=capacity;i++){
        if(weight[0]<=i){ //check if weight[0] can fit in current capacity i
            dp[0][i] = value[0];
        }
        else{
            dp[0][i] = 0;
        }
    }
    for(int index=1;index<n;index++){
        for(int w=0;w<=capacity;w++){
            int include = 0;
            if(weight[index]<=w){ //check if the current item can be included in the knapsack, by check for different capacity values
                include = value[index] + dp[index-1][w-weight[index]];//if it can be included, we add its value(value[index]) to the maximum value of the remaining capacity (w-weight[index]).
            }
            int exclude = 0 + dp[index-1][w]; 
            dp[index][w] = max(include,exclude);
        }
    }
    return dp[n-1][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	int index=0;
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,dp);
}