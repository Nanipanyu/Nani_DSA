#include <iostream>
using namespace std;
void print(int arr[][4], int r, int c){
    int i=0;
    int j=c-1;
    int count =0;
    while(count<r*c ){
        for(int a=i;a<=j;a++){
            cout<<arr[i][a]<<" ";
            count++;
        }
        for(int a=i+1;a<=r-i-1;a++){
            cout<<arr[a][j]<<" ";
            count++;
        }
        for(int a=j-1;a>=c-j-1;a--){
            cout<<arr[r-i-1][a]<<" ";
            count++;
        }
        for(int a=r-i-2;a>=i+1;a--){
            cout<<arr[a][c-j-1]<<" ";
            count++;
        }
        i++;
        j--;
    }
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
    // cout<<num[2][1]<<endl;
    print(num,4,4);
}
