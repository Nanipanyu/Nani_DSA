#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int fibonacci(int n, vector<int> &dp){
        if(n<=1){
                return n;
        }
        if(dp[n]!=-1){
                return dp[n];
        }
        dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
        return dp[n];
}

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;
        vector<int> dp(n+1,-1);
        int ans = fibonacci(n,dp);
        cout<<ans;
}