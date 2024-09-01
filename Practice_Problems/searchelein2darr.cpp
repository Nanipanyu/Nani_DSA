#include<iostream>
using namespace std;
void ispresent(int arr[][4],int ele,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(ele==arr[i][j]){
                cout<<i<<" "<<j;

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
    ispresent(num,5,3,4);

}


