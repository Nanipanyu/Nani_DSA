#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
//There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints. You can take cards from the beginning or from the end of the row. 
//You have to take exactly k cards. Your score is the sum of the points of the cards you have taken. Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

class Solution {
public:
    int getsum(vector<int>& cards,int k){
        int ans=0;
        for(int i=0;i<k;i++){
            ans=ans+cards[i];
        }
        return ans;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int rsum = 0;
        int maxsum=getsum(cardPoints,k);
        int lsum = maxsum;
        if(k==n){
            return maxsum;
        }
        for(int i=1;i<=k;i++){
            lsum=lsum-cardPoints[k-i];
            rsum=rsum+cardPoints[n-i];
            maxsum=max(maxsum,(lsum+rsum));
        }
        return maxsum;
    }

};




///

class Solution {
public:
    int getsumrev(vector<int>& cards,int &k,vector<vector<int>> &dp,int posn,int count){
        if(count>k || posn<0){
            return 0;
        }
        if(count == k){
            return cards[posn];
        }
        if(dp[posn][count] != -1){
            return dp[posn][count];
        }
        int take = cards[posn] + getsum(cards,k,dp,posn-1,count+1);
        int skip = getsum(cards,k,dp,posn-1,count+1);
        return dp[posn][count] = max(take,skip);
    }

    int getsum(vector<int>& cards,int &k,vector<vector<int>> &dp,int posn,int count){
        if(count>k || posn<cards.size()){
            return 0;
        }
        if(count == k){
            return cards[posn];
        }
        if(dp[posn][count] != -1){
            return dp[posn][count];
        }
        int take = cards[posn] + getsum(cards,k,dp,posn+1,count+1);
        int skip = getsum(cards,k,dp,posn+1,count+1);
        return dp[posn][count] = max(take,skip);
    }

    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(int i=0;i<cardPoints.size();i++){
            sum = sum + cardPoints[i];
        }
        if(k == cardPoints.size()){
            return sum;
        }
        vector<vector<int>> dp(cardPoints.size(),vector<int> (k+1,-1));
        int st = getsum(cardPoints,k,dp,1,1) + cardPoints[0];
        int end = getsumrev(cardPoints,k,dp,cardPoints.size()-2,1) + cardPoints[cardPoints.size()-1];
        return max(st,end);
    }
};