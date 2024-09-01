#include<iostream>
using namespace std;
int& update(int n){
    int m=n;
    int& a=m; 
    cout<<a<<endl;
    return a;
}
int main(){
    int i=5;
    // int &j=i;
    cout<<update(i);
    int n;
    cout<<" Enter a value"<<" ";
    cin>> n;
    int* arr=new int[n]; // variable size array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }  
}