#include<iostream>
using namespace std;
void bsrch(int arr[][5],int r,int c,int target){
    int row=0;
    int col=c-1;
    while(row<r && col>=0){
        int ele=arr[row][col];
        if(ele==target){
            cout<<"index is"<<row<<" "<<col; 
            break;           
        }
        else if(ele<target){
            row++;
        }
        else{
            col--;
        }
    }    
}

int main(){
    int num[5][5];
    cout<<"Enter your character"<<" ";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>> num[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<num[i][j]<<" ";
        }
        cout<<endl;

}
    bsrch(num,5,5,13);

}
