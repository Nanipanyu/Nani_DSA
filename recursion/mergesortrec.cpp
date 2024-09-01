#include<iostream>
using namespace std;
void merge(int s,int e,int *arr){
    int mid=s+(e-s)/2;
    int len1=mid+1-s;
    int len2=e-mid;
    int mainindex = s;
    int *arr1=new int[len1];
    int *arr2=new int[len2];
    for (int i=0;i<len1;i++){
        arr1[i]=arr[s++];
    }
    int k=mid+1;
    for(int j=0;j<len2;j++){
        arr2[j]=arr[k++];
    }
    int i =0;
    int j =0;
    s = mainindex;
    while(i<len1 && j<len2){
        if(arr1[i]<arr2[j]){
            arr[s++]=arr1[i++];
        }
        else{
            arr[s++]=arr2[j++];
        }
    }
    while(i<len1){
        arr[s++]=arr1[i++];
    }
    while(j<len2){
        arr[s++]=arr2[j++];
    }
    delete []arr1;
    delete []arr2;
}
void mergesort(int *arr,int s,int e){
    int mid=s+(e-s)/2;
    if(s>=e){
        return;
    }
    // left array
    mergesort(arr,s,mid);
    // right array
    mergesort(arr,mid+1,e);
    // merging
    merge(s,e,arr);
}

int main(){
    int num[10]={2,4,13,75,12,3,9,52,63,1};
    mergesort(num,0,9);
    for(auto i:num){
        cout<<i<<" ";
    }

}