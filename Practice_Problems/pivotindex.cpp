#include<iostream>
using namespace std;
int pivot(int arr[],int n){
int s=0;
int e=n-1;
int mid=s+(e-s)/2;
int ans=0;
while(s<e){
    if(arr[mid]>=arr[0]){
        s=mid+1;
        }
    else{
        e=mid;

        }
    mid=s+(e-s)/2;
        }
return s ;    
}
int main(){
    int num[9]={4,5,6,7,8,0,1,2,3};
     
    cout<<"your pivot is"<< pivot(num,9);
}