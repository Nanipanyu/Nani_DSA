#include<iostream>
using namespace std;
bool ispresent(int arr[],int n,int m){
    if(arr[0]==m){
        return true;
    }
    if(n==0){
        return false;
    }   
    else{
        bool ans=ispresent(arr+1,n-1,m);
    }  
}
int main(){
    int arr[10];
    cout<<"Enter your values"<<" ";
    for(int i=0;i<10;i++){
        cin>>arr[i]; 
    }
    int m;
    cout<<"Enter the value to check"<<" ";
    cin>>m;
    if(ispresent(arr,10,m)){
        cout<<m<<" "<<"is present";
    }
    else{
        cout<<m<<" "<<"is not present";
    }
}