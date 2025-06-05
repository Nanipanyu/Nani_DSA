#include <bits/stdc++.h>
using namespace std;

//Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
// A 1-day pass is sold for 'COST'[0] coins,
// A 7-day pass is sold for 'COST'[1] coins, and
// A 30-day  pass is sold for 'COST'[2] coins.
// help the Ninja to find the minimum number of coins required to complete his tour

int mincost(int index,int n, vector<int> days, vector<int> cost,vector<int> &dp)
{
    if(index>=n){
        return 0;
    }

    if(dp[index]!=-1){
        return dp[index];
    }
    int option1=cost[0]+mincost(index+1,n,days,cost,dp);

    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);  //if taking 7 days pass, we can travel for 7 days from the current index, so next index will be after 7 days.
    int option2 = cost[1]+mincost(i,n,days,cost,dp);

    for(i=index;i<n && days[i]<days[index]+30;i++);//  //if taking 30 days pass, we can travel for 30 days from the current index, so next index will be after 30 days.
    int option3 = cost[2]+mincost(i,n,days,cost,dp);
    
    dp[index]=min(option1,min(option2, option3));
    return dp[index];
}

int SolveTab(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1,INT_MAX);
    dp[n]=0;  //backtracking base case, if we have no days left to travel, we need 0 coins.
    //we will start from the last day and move to the first day, so we can use the dp array to store the minimum coins required for each day.

    for(int k=n-1;k>=0;k--){
        int option1=cost[0]+dp[k+1]; //take 1 day pass, and go backwards, the front was the mincost for till that day.

        int i;
        for(i=k;i<n && days[i]<days[k]+7;i++); //when went a day back , check for the cost of forward seven days using seven day pass(later we will check  that if it would have been cheaper travelled with 7 days pass)
        int option2 = cost[1]+dp[i];  //dp[i]=min cost till the (last/7th day/for 7 daypass)day just after we  travel with 7 days pass.

        for(i=k;i<n && days[i]<days[k]+30;i++);
        int option3 = cost[2]+dp[i];  //dp[i]=min cost till the (last/30th day/for 30 daypass)day just after we  travel with 30 days pass.

        dp[k]=min(option1,min(option2, option3));  //when went a day back , check for the cost of forward 30 days using seven day pass(later we will check  that if it would have been cheaper travelled with 30 days pass)
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1,-1);
    return mincost(0,n,days,cost,dp);
}