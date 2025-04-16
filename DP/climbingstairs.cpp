#include <bits/stdc++.h> 
using namespace std;

long long rec(long long nStairs,vector<long long> &stepi){
    if(nStairs<=1){
        return 1;
    }
    if(stepi[nStairs]!=-1){
        return stepi[nStairs];
    }
    stepi[nStairs]= (rec(nStairs-1,stepi)+rec(nStairs-2,stepi)) % 1000000007;
    return stepi[nStairs];
}

int countDistinctWays(long long nStairs) {
    //  Write your code here.
    vector<long long> stepi(nStairs+1,-1);
    long long ways = rec(nStairs,stepi);
    return ways;
}