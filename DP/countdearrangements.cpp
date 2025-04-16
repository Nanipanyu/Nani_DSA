#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MOD 1000000007

long long int D(int n,vector<int> &dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = ((n-1) *(D(n-1,dp) + D(n-2,dp)))%MOD; // if we take the first element, we can place it in n-1 positions(so multiply), and the rest of the elements can be arranged in D(n-1) ways. If we don't take the first element(i.e if we swap the kth element(k=where 1st has been placed) in 1st postion), we can place it in n-2 positions, and the rest of the elements can be arranged in D(n-2) ways.
    //D(n-1) is for the the remaining elements :Ex-(5,4,3,2,[1]) 1 has been fixed in 5th posn now we dearrange for (5,4,3,2)=n-1 (see it as (1,2,3,4)), but then D(n-2) comes because in (5,4,3,2) we can keep 5 fixed and swap other elements , but if (1,2,3,4) we cant keep 1 fixed case, so (n-2) case comes in.
    return dp[n];
}

long long int tab(int n){
    vector<long long int> dp(n+1,0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i=3;i<=n;i++){
        dp[i] = ((i-1) * (dp[i-1] + dp[i-2]))%MOD;
    }
    return dp[n];
}

long long int countDerangements(int n) {
    vector<int> dp(n+1,-1);
    int count = D(n,dp)%MOD;
    int count = tab(n)%MOD;  // int count = tab(n)%MOD; // using tabulation
    return count;
}