#include<iostream>
using namespace std;
int merge(int s,int e,int *arr){
    int cnt=0;
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
            // if an element of left part say [i] is greater than a element in right part(than all the elements in the right of 'i'will be greater than elemment in right part)
            cnt=cnt+len1-i;
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
    return cnt;
}
int mergesort(int *arr,int s,int e){
    int count=0;
    int mid=s+(e-s)/2;
    if(s>=e){
        return count;
    }
    
    //left array Adding count coming from left portion
    count+=mergesort(arr,s,mid);
    // right array and Adding count coming from right portion
    count+=mergesort(arr,mid+1,e);
    // merging
    count+=merge(s,e,arr);
    return count;

}
int main(){
    int num[5]={1,20,6,4,5};
    cout<<"YOur count is"<<mergesort(num,0,4);
}