#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define mod 1000000007

//Problem: https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
//Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.
//'N' = 3, 'K' = 2 , Out put :6 , Explanation: 2 colors are there, so we can paint the fence in 6 ways. (1,2,1) , (1,1,2) , (2,1,1) , (2,2,1) , (1,2,2) , (2,1,2).



long long int add(long long int a,long long int b){
    return (a%mod + b%mod)%mod;
}
long long int mult(long long int a,long long int b){
    return (a%mod * b%mod)%mod;
}

long long int solve(long long int n,long long int k,vector<long long int> &dp){
    if(n==1){  //if only one post is there, we can paint it in k ways.
        return k;
    }
    if(n==2){  //if two posts are there, to paint it in diff colour we can paint it in k ways for the first post and (k-1) ways for the second post, so total = k*(k-1).
        return add(k,mult(k,k-1)); //same color for both posts = k, diff color for both posts = k*(k-1)
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = add(mult(solve(n-2,k,dp),k-1),mult(solve(n-1,k,dp),k-1)); //From maths: either we can paint the last 2 post in same color , or we can paint it in  different colors. So, if we paint it in the same color, we have (k-1)*solve(n-2) options (k-1 multiplied beacuse every combination in solve(n-2) cant attached with one comination of last 2 post(ex;RR,GG) because then rule will break) . If we paint it in a different color, we have solve(n-3)*k-1 options (k-1)is multiplied beacause  every combination in solve(n-3) cant attached with one post of same colour post(ex; last 2 post cant beacome :RR,GG)so they have(k-1)option because then last 2post wont be of diff colour which was our condition
    return dp[n];
}
long long int numberOfWays(int n, int k) {
    // Write your code here.
    vector<long long int> dp(n+1,-1);
    long long int ways = solve(n,k,dp);
    return ways;
}