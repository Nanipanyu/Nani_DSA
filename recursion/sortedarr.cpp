#include<iostream>
using namespace std;
bool check(int arr[],int n){
    if(n==0 || n==1){
        return true;
    }
     if(arr[0]>arr[1]){
        return false;
     }
     bool ans=check(arr+1,n-1);
     return ans;
     
}
int main(){
    int arr[10];
    cout<<"Enter your arr values"<<" ";
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    cout<<check(arr,10);
}
