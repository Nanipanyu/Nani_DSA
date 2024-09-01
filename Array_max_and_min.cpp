#include<iostream>
using namespace std;
int func(int num[],int n){
    int max = INT32_MIN;
    for(int i=0;i<n;i++){
        if(num[i]>max){
            max=num[i];
            }

        }
    return max;    

    }
int main(){
    int size;
    cout<<"Your size";
    cin>> size;
    int arr[size];
        cout<<"your nums";

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"max is"<< func(arr,size);

}    
