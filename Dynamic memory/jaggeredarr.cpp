#include<iostream>
using namespace std;

int main(){
    
    int row;
    int col;
    cout<<"Enter your row"<<endl;
    cin>>row;
    int *store = new int[row];
    // cout<<"Enter your col"<<endl;
    // cin>>col;
    int **arr=new int*[row];
    for(int i=0;i<row;i++){
        cout<<"enter no. of column"<<endl;
        cin>>col;
        arr[i]=new int[col];
        store[i] = col;
        cout<<"enter your matrix values"<<endl;  
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    
    // cout<<"size of array is"<<sizeof(arr)<<endl;
  
    int p=0;
    for(int i=0;i<row;i++){

        for(int j=0;j<store[i];j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

