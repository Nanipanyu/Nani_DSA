#include<iostream>
using namespace std;
void rotate(int arr[],int n,int k){
int arr2[n]={0};
for(int k=0;k<n;k++){
    arr2[k]=arr[k];
}    
for(int i=0;i<n;i++){
    if((i+k)<n){
        arr2[i+k]=arr[i];
        }
    else{
        arr2[(i+k)%n]=arr[i];
    }    
} 
arr=arr2;   
for(int j=0;j<n;j++){
    cout<<arr[j]<<" ";
}

}
int main(){
int num[5]={1,5,7,9,11};
rotate(num,5,3);
}