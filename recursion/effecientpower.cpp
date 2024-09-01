#include<iostream>
using namespace std;
int powerfunc(int n,int m){
    int num=0;
    if(m==1){
        return n;
    }
    if(m&1){
        num=n*(powerfunc(n*n,m/2));
    }
    else{
        num=powerfunc(n*n,m/2);
    }
    return num;
}
int main(){
    int a,b;
    cout<<"Enter your number"<<endl;
    cin>>a;
    cout<<"Enter your power"<<endl;
    cin>>b;
    cout<<"Answer is"<<powerfunc(a,b);
}