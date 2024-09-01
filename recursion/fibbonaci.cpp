#include<iostream>
using namespace std;
int getnum(int n){
    if(n==1 ){
        return 0;
    }
    if(n==2){
        return 1;
    }
    int function=getnum(n-1)+getnum(n-2);
    return function;



      
}
int main(){
    int n;
    cout<<"position in fibbonaci series"<<" ";
    cin>>n;
    cout<<getnum(n);
}