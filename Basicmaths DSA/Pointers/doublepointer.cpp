#include<iostream>
using namespace std;
int main(){
    int i=5;
    int *p=&i;
    int **p2=&p;
    cout<<"address of i"<<p<<endl;
    cout<<"value of i"<<*p<<endl;
    cout<<" address of p"<<p<<endl;
    cout<<"value of i"<<**p2<<endl;






}