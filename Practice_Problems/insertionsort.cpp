#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];  //shifting the left element to right

            }
            else{
                break;
            }
        }
        arr[j+1]=temp;

    }
    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
    }
}

int main(){
    int num[5]={10,1,7,4,11};
    insertion_sort(num,5);
}