#include<iostream>
using namespace std;
void bubble(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
        // cout<<arr[n-1-i]<<" ";
    // for(int i=0;i< n/2;i++){
    // int s=arr[i] ;
    // arr[i]=arr[4-i] ;
    // arr[4-i]=s;

    // }
    // // in c++ if you try to print an arrray using the name of the array ,the address of the first element in array is printed
    for(int j=0;j<n;j++){

    
    cout<<arr[j]<<" ";
}

    
}
    
    

int main(){
    int num[5]={5,4,3,2,1};
    bubble(num,5);
}
