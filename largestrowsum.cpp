#include<iostream>
#include<algorithm>
using namespace std;
void maxrow(int arr[][4],int r,int c){
    
    
    int m=-1; 
    int sum=0;
    int n=0;

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            sum=sum+arr[i][j];
        }
        
        if(sum>m){
            m=sum;
            n=i;
        }  
        sum=0;

    }
   
    cout<<"row whose sum is max"<<n;

}
int main(){
    int num[3][4];
    cout<<"Enter your character"<<" ";
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>> num[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
    maxrow(num,3,4);
}
