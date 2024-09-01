#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
using namespace std;
// int main(){
// int num[5]={1,4,7,8,9};
// int jug[4]={22,25,34,99};
// vector<int>v;
// for(int j=0;j<4;j++){
//     v.push_back(jug[j]);
        
//     }

// for(int i=0;i<5;i++){
//     v.push_back(num[i]);
// }

// sort(v.begin(),v.end()); 
// for(int i:v){
//     cout<<i<<" ";
// }

// cout<<endl;


// }
void merge(int arr1[],int n,int arr2[],int m,int arr3[]){
    int k=0;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            arr3[k]=arr1[i];
            i++;
        }
        else{
            arr3[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<n){
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    while(j<m){
        arr3[k]=arr2[j];
        j++;
        k++;
    }
    
}
void print(int ans[],int n){
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int num[5]={1,22,31,33,99};
    int tum[3]={32,44,66};
    int lew[8]={0};
    merge(num,5,tum,3,lew);
    print(lew,8);


}

