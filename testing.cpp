#include<iostream>
#include<array>
using namespace std;
// int pivot(int arr[],int n,int key){
// int s=0;
// int e=n-1;
// int mid=s+(e-s)/2;
// int ans=0;
// while(s<e){///////
//     if(arr[mid]>=arr[0]){
//         s=mid+1;
//         }
//     else{
//         e=mid;

//         }
//     mid=s+(e-s)/2;///////
//         }
// e=n-1; ////////

// if(key>= arr[s]){
//     int Mid=s+(e-s)/2;
//     while(s<=e){
//         if(key==arr[Mid]){//////////
//             return Mid;
//         }
//         else if(key>arr[Mid]){
//             s=Mid+1;
//         }
//         else{
//             e=Mid-1;
//         }
//     Mid=s+(e-s)/2;
//     }
        
//     }
// else{
//     int S=0;
//     int E=s-1;
//     int M=(s-1)/2;
//     while(S<=E){
//         if(key=M){
//             return M;
//         }
//         else if(key>arr[M]){
//             S=M+1;
//         }
//         else{
//             E=M-1;
//         }
//         M=S+(E-S)/2;
//     }
// }    


 
// }
// int main(){
//     int num[5]={7,1,3,5,6};
//     cout<<"your variable index is"<< pivot(num,5,5);
// }
int main(){
    array<int,4> a={1,2,3,4};
    int size=a.size();
    cout<<size;
}