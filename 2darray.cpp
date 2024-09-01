#include<iostream>
using namespace std;
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
}
