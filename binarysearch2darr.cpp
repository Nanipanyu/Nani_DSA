#include<iostream> 
using namespace std;
int binarysrch(int arr[][4],int r,int c,int target){
    int s=0;
    int e=r*c-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        int ele=arr[mid/c][mid%c];
        if(target==ele){
            cout<<"Index : "<<mid/c<<" "<<mid%c<<endl;
            return 1;
        }
        else if(ele<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
        
    }
    return 0;
}
int main(){
    
    int num[4][4];
    cout<<"Enter your character"<<" ";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>> num[i][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"index of target is"<<" "<<binarysrch(num,4,4,3);
    
    
}


