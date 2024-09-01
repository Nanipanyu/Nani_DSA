#include <iostream>
using namespace std;
void spiralprnt(int arr[][4], int r, int c){
    int R=0;
    int C=0;
    int endR=r-1;
    int endC=c-1;    
    int count=0;  
    while (count<r*c){    
       for(int i=C;i<=endC && count<r*c;i++){
        cout<<arr[R][i]<<" ";        
        count++;
       }
       R++;
       for(int i=R;i<=endR && count<r*c;i++){
        cout<<arr[i][endC]<<" ";
        count++;
       }
        endC--;

       for(int i=endC;i>=C && count<r*c;i--){
        cout<<arr[endR][i]<<" ";
        count++;
       }
        endR--;

       for(int i=endR;i>=R && count<r*c;i--){
        cout<<arr[i][C]<<" ";
        count++;
       }
        C++;

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
    spiralprnt(num,4,4);
}


