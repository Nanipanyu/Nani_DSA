#include<iostream>
using namespace std;
int main(){
    int row;
    int col;
    cout<<"Enter your row"<<endl;
    cin>>row;
    cout<<"Enter your col"<<endl;
    cin>>col;
    // creating a 2d array
    int **arr=new int*[row];
    for(int i=0;i<row;i++){
        arr[i]=new int[col];
    }
    
    // taking input
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }

      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    // deleting heap memory
      for(int i=0;i<row;i++){
        delete []arr[i];
    }
    delete []arr;





}