#include<iostream>
using namespace std;
void bubble(int *arr,int n){
    // base case
    if(n==1){
        return;    
    }
    // 1 case solve
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    // recursive call
    bubble(arr,n-1);    
}
int main(){
    int arr[11]={21,3,20,1,35,2,5,7,13,14,33};
    bubble(arr,10);
    for(auto i:arr){
        cout<<i<<" ";
    }
}