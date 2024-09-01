#include<iostream>
using namespace std;
int search(int arr[],int size,int key){
    int s=0;
    int e=size-1;
    int mid=(s+e)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
            }
        else if(arr[mid]>key){
            e=mid-1;

        } 
        else{
            s=mid+1;
        } 
        mid=(s+e)/2 ; 
    }


}
int main(){
    int even[6]={2,6,8,24,56,78};
    int odd[5]={1,20,45,56,76};
    cout<<"index of 56 is"<<search(even,6,56);
    cout<<"index of 1 is"<<search(odd,5,1);
}