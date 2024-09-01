#include<iostream>
using namespace std;
int part(int arr[],int n,int m){
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int e=sum;
    int mid=sum/2;
    while(s<=e){
        int add=0;
        int t=0;
        
        int p=1;
        for(int j=0;j<n;j++){
            if(add+arr[j]<=mid){
                add=add+arr[j];

            }
            else if(arr[j]>mid){
                t=1;               
                break;

            }
            else{
                p=p+1;
                add=arr[j];
            
            }
                
            
            
        }
        if(p>m || t==1){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return mid;
}

int main(){
    int num[5]={20,55,10,2,11};
    cout<<"your partition is "<<part(num,5,4);
}