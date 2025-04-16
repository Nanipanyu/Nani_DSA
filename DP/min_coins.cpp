#include <bits/stdc++.h> 
using namespace std;

//In these case we are given a amt vector with random amounts, ex=[3,2,1] or [1,7,3,5] , and a cost X is given we need to choose min no of coins from amt to make up the cost X

int minimise(vector<int> &num,int x,vector<int> &dp){ // we will start from amount X , and gradually reduce it using all combination with num , and take the combination with least step
    if(x==0){ // if our combination of coins has added upto X (x==0 , because we will move in decreasing amount order, decrease amt(from num) from x)
        return 0;
    }
    if(x<0){ // If we overshoot x, i.e our combination of coins was not making upto X
        return INT_MAX ;
    }
    if(dp[x]!=-1){ // memoization available then return from here,
        return dp[x];
    }
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){ // for each amt(x) , we have to check all combination of coins in num 
        int ans = minimise(num,x-num[i],dp); //Go and check for the next coin combination for amt x-num[i];
        if(ans!=INT_MAX){ // means not allowed if no valid combination of number in num can sum upto x(x can be middle amount(not reached final amt X), after reducing X to some amount xi, now it overshoots with all values in num, so no possible combination)
            mini=min(mini,ans+1); //(ans+1 = counting no. of steps/combination , +1 is for x-num[i] step), take/update the minimum combination among all combination from values in num , 
        }
    }
    dp[x]=mini;
    return mini; 
}


int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int> dp(x+1,-1); //memoization
    int ans = minimise(num,x,dp);
    if(ans==INT_MAX){ //if the amounts in num is not able to make up X with any combination then return -1
        return -1;
    }
    return ans;
}