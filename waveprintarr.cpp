#include<iostream>
using namespace std;
void print(int arr[][4],int r ,int c){
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            if(i%2==0){
                cout<<arr[j][i]<<" ";
            }
            else{
                cout<<arr[r-j-1][i]<<" ";
            }
        }
    }
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
    // cout<<num[2][1]<<endl;
    print(num,3,4);
}