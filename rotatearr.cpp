#include<iostream>
using namespace std;
void rotate(int arr[][4],int r,int c){
    int dum[r][c];
  
    int R=0;
    int C=c-1;
    int count=0;
    while(count<r){
    for(int i=0;i<r;i++){
        dum[i][C]=arr[R][i];
    }
    C--;
    R++;
    count++; 
    }
     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<dum[i][j]<<" ";
        }
        cout<<endl;
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
    rotate(num,4,4);
    
    // cout<<"index of target is"<<" "<<binarysrch(num,4,4,3);
    
    
}


