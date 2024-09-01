#include<iostream>
using namespace std;
int search(int arr[],int n){
int s=0;
int e=n-1;
int mid=s+((e-s)/2);
int ans=0;

while(s<e){
    ans=mid;
    if(arr[mid]<arr[mid+1]){
        s=mid+1;
        }
    else if(arr[mid]<arr[mid-1]){
        e=mid-1;
        }
    else{
        int a=mid;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            break;  
        }
        else{
            for(int i=a;i<=e;i++){
                if( arr[i]>arr[mid]){
                    mid=i;
                    s=i;
                }
            }
            for(int i=s;i<=a;i++){
                if(arr[i]>arr[mid]){
                    mid=i;
                    e=i;
                }

            }        
               

                
            }
        }   
        
        

        
    mid=s+((e-s)/2);

    }
return ans;
}


int main(){
    int box[6]={2,9,6,3,3,2};
    cout<<"your peak index is "<<search(box,11);

}