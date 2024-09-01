#include<iostream>
using namespace std;
int search(int arr[],int size, int key){
int s=0;
int e = size -1;
int mid=s+((e-s)/2);
int ans=-1;
while(s<=e){
    if(key==arr[mid]){
        ans=mid;
        e=mid-1;
    }
    else if(key<arr[mid]){
        e=mid-1;
    }
    else if(key>arr[mid]){
        s=mid+1;
    }
    mid=s+((e-s)/2);

}
return ans;
}
int find(int arr[],int size, int key){
int s=0;
int e = size-1;
int mid=s+(e-s)/2;
int que=-1;
while(s<=e){
    if(key==arr[mid]){
        que=mid;
        s=mid+1;
    }
    else if(key<arr[mid]){
        e=mid-1;
    }
    else if(key>arr[mid]){
        s=mid+1;
    }
    mid=s+((e-s)/2);

}
return que;
}

int main(){
    int num[9]={0,1,7,7,7,8,9,10,11};
    cout<<"first position is"<<search(num,7,7)<<endl;
    cout<<"last position is"<<find(num,7,7);
}