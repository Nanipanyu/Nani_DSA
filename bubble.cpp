#include<iostream>
using namespace std;

void fun(int arr[],int n,int index=0,int count=0){
    if(count==n-1){
        return;
    }
    int i=index;
    while(arr[i]>=arr[i+1] && i<n-1){
        swap(arr[i],arr[i+1]);
        i++;
    }
    fun(arr,n,index,count+1);
}

int main(){
    int arr[5]={1,4,3,2,5};
    fun(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
}
