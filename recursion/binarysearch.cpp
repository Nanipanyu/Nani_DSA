#include<iostream>
using namespace std;
int binarysearch(int arr[],int s,int e,int m){
    if(s>e){
        return -1;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==m){
        return mid;
    }
    if(arr[mid]>m){
        return binarysearch(arr,s,mid-1,m);
    }
    if(arr[mid]<m){
        return binarysearch(arr,mid+1,e,m);
    }
}
int main(){
    int arr[10];
    int m;
    cout<<"Enter your values"<<" ";
    for(int i=0;i<10;i++){
        cin>>arr[i]; 
    }
    cout<<"Enter your number to find"<<" ";
    cin>>m;
    cout<<"index is"<<binarysearch(arr,0,9,m);
}