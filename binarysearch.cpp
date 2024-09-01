#include<iostream>
using namespace std;
int main(){
    int num[6]={3,7,12,13,45,67};
    int key=67;
    int s=0;
    int e=5;
    int mid=(s+e)/2;
    while(s<=e){
        if(num[mid]==key){
            cout<<"index is"<<mid;
            break;
        }
            
        else if(num[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    
    

}