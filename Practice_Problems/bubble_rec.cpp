#include<iostream>
#include<algorithm>
using namespace std;

void f(int *arr,int n,int &s){
    if(s==n-1){
        return;
    }
    int i=0;
    while(i<n-1){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
        i++;
    }
    s++;
    f(arr,n,s);    
}
int main(){
    int arr[5]={5,4,3,2,1};
    int s=0;
    f(arr,5,s);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}