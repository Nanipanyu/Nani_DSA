#include<iostream>
#include<climits>
using namespace std;
void insertion(int *arr,int n,int &s){
    if(s==n-1){
        return;
    }
    int i=s;  
    int mini=INT_MAX ;
    int posn=s; 
    while(i<n){
        if(arr[i]<mini){
            mini=arr[i];
            posn=i;
        }
        i++;
    }
    swap(arr[s],arr[posn]);
    s++;
    insertion(arr,n,s);
}
int main(){
    int s=0;
    int arr[5]={5,4,3,2,1};
    insertion(arr,5,s);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}