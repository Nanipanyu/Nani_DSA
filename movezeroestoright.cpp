#include<iostream>
using namespace std;
#include<algorithm>

void remove(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[j],arr[i]);
            j++;
            // if(arr[j]==0){
            // arr[j]=arr[i];
            // arr[i]=0;
            // }
            // j++;

        }
    }
    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }

}


int main(){
    int num[8]={0,1,0,0,0,6,0,9};
    int tum[5]={1,0,0,0,5};
    cout<<"new num"<<" ";
    remove(num,8);
    cout<<"new tum"<<" ";
    remove(tum,5);

}