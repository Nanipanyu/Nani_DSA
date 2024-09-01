#include<iostream>
using namespace std;
int pivot(int arr[],int n,int key){
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
e=n-1 ;       

if(key>= arr[s] && key<arr[0]){
    int Mid=s+(e-s)/2;
    while(s<=e){
        if(key==arr[Mid]){
            return Mid;
        }
        else if(key>arr[Mid]){
            s=Mid+1;
        }
        else{
            e=Mid-1;
        }
    Mid=s+(e-s)/2;
    }
        
    }
else{
    int S=0;
    int E=s-1;
    int M=(s-1)/2;
    while(S<=E){
        if(key==M){
            return M;
        }
        else if(key>arr[M]){
            S=M+1;
        }
        else{
            E=M-1;
        }
        M=S+(E-S)/2;
    }
}    


 
}
int main(){
    int num[9]={11,13,0,1,2,3,6,8,9};
    cout<<"your variable index is"<< pivot(num,9,11);
}