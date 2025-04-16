#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int,int> count;
    int i=0;
    while(i<n){
        count[arr[i]]++; //if the key does not exist it creates a key and increaase its count by 1
        i++;
    }
    int maxi=INT_MIN;
    int ans=0;
    for(auto i:count){
        if(i.second > maxi){
            maxi = i.second;
            ans=i.first;
        }
    }
}

int maximumFrequencywithcond(vector<int> &arr, int n)
{
    //if two ele contend for max frequency than return the ele which is in the lower index
    //Write your code here
       //Write your code here
    unordered_map<int,int> count;
    int maxfreq=INT_MIN;
    int maxcount=-1;
    int i=0;

    while(i<n){
        count[arr[i]]++; //if the key does not exist it creates a key and increaase its count by 1
        maxfreq=max(maxfreq,count[arr[i]]);
        i++;
    }
    for(int j=0;j<n;j++){
        if(maxfreq==count[arr[j]]){
            maxcount = arr[j];
            break;
        }
    }
    return maxcount;
}

int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    int n=arr.size();
    int maxFrequency = maximumFrequency(arr, n);
}