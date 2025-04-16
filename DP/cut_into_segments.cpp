#include<iostream>
#include <climits> 
#include <vector>
using namespace std;

//Here we have to cut the rod of length n into segments of length x,y,z and we have to find the max no of segments we can get(Ex: n=5,x=2,y=3,z=1, we can get all 5segments of length 1, so ans=5)
//We will start from 0 and keep on adding x,y,z to it and check if we reach n, if we reach n we will return 0, if we overshoot n we will return INT_MIN, if we reach a point where we have already calculated the max no of segments we can get from that point we will return that value
int solve(int n,int sum,vector<int> &v,vector<int> &dp){
	if(sum>n){ //we overshoot n
		return INT_MIN;
	}
	if(sum==n){ //we reach n
		return 0;
	}
	if(dp[sum]!=INT_MIN){ //we have already calculated the max no of segments we can get from this point
		return dp[sum];
	}
	int maxi = INT_MIN; //initially INT_MIN because we have to find max no of segments
    //We will try all possible combinations of x,y,z and check if we can reach n
	for(int i=0;i<3;i++){
		int count = solve(n,sum+v[i],v,dp);
		if(count!=INT_MIN){//if we reach a combination where we reach n , we will update maxi which will be the max no of segments/steps currently we have in this combination
			maxi = max(count+1,maxi);
		}
	}
	dp[sum]=maxi;
	return maxi;
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	int sum=0;
	vector<int> v = {x,y,z};
	vector<int> dp(n,INT_MIN);
	int ans = solve(n,sum,v,dp);
	if(ans==INT_MIN){
		return 0;
	}
	return ans;
}


//or you can iterate from n to 0 and check for all possible combinations of x,y,z and check if we can reach n

int solve(int n,vector<int> &v,vector<int> &dp){
	if(n<0){
		return INT_MIN;
	}
	if(n==0){
		return 0;
	}
	if(dp[n]!=INT_MIN){
		return dp[n];
	}
	int maxi = INT_MIN;
	for(int i=0;i<3;i++){
		int count = solve(n-v[i],v,dp);
		if(count!=INT_MIN){
			maxi = max(count+1,maxi);
		}
	}
	dp[n]=maxi;
	return maxi;
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int> v = {x,y,z};
	vector<int> dp(n+1,INT_MIN);
	int ans = solve(n,v,dp);
	if(ans==INT_MIN){
		return 0;
	}
	return ans;
}

