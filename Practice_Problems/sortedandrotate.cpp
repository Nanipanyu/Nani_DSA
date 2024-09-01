#include<iostream>
using namespace std;
bool check(int arr[],int n){
    int s=0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            s++;        
        }
        
        }
    if(arr[n-1]>arr[0]){
        s++;
    }
    if(s<=1){
        return true;
    } 
    else{   
    
    return false;
    }
}

void print(int arr[],int n){
    if(check(arr,n)){
        cout<<"perfect"<<endl;
    }
    else{
        cout<<"wrong format"<<endl;
    }
}

int main(){
    int num[5]={1,2,3,4,5};
    int tum[5]={3,4,5,0,1};
    int lum[5]={1,1,1,1,1};

    print(num,5);
    print(tum,5);
    print(lum,5);



}