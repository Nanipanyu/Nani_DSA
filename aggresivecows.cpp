#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool ispossible(int arr[],int mid,int k,int n){
    
    int lastcount=arr[0];
    int cow=1;
    
    for(int i=0;i<n;i++){

        if((arr[i]-lastcount)>=mid){
            cow++;
            if(cow==k){
                return true;
            }
            lastcount=arr[i];
        }
    }
    return false;
    

}
int space(int arr[],int n,int k){
    sort(arr,arr+n);
    int s=0;
    int a=0;
    int b = INT_MAX; 

    for(int i=0;i<n;i++){
        a=max(a,arr[i]);

        b=min(b,arr[i]);

    }
    int e=a-b;
    
    int mid=s+(e-s)/2;
    ;
    
    while(s<e){

        if(ispossible(arr,mid,k,n)){
            s=mid+1;

        }
        else{
            e=mid-1;
        }
        mid=s+((e-s)/2);
        
            
        
        
    }
    return mid;
}




int main(){
    int cows[9]={55,43,21,78,4,7,1,15,11};
    cout<<"you can place them max at"<<space(cows,9,3);
}

