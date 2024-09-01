#include<iostream>
using namespace std;
int search(int x){
    int num[x+1];
    int s=0;
    int e=x;
    long long int mid=s+(e-s)/2;
    long long int ans=-1;
    
    for(int i=0;i<x;i++){
        num[i]=i;
        
    }
    while(s<=e){
        if((mid*mid)==x){
            return mid;
            

            
        } 
        else if((mid*mid)<x){
            ans=mid;

            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;

    }
   

}

int main(){
    int b;
    cout<<"whose square do you want"<<endl;

    cin>>b;
    cout<<search(b);
}