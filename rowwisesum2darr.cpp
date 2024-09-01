#include<iostream>
using namespace std;
void summ(int num[][4],int r ,int c){
     for(int i=0;i<r;i++){
        int sum=0;
        for(int j=0;j<c;j++){
            sum=sum+ num[i][j];
        }
        cout<<sum<<" ";
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
    summ(num,3,4);
}
