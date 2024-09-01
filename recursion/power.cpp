#include<iostream>
using namespace std;
int power(int n,int m){
    if(m==1){
        return n;
    }
    int smaller=power(n,m-1);
    int bigger=n*smaller;
    return bigger;
}
int main (){
    int n;
    int m;
    cout<<"enter your integer"<<" ";
    cin>>n;
    cout<<"enter your power"<<" ";
    cin>>m;
    cout<<power(n,m);
}