#include<iostream>
using namespace std;
int main(){
    int i=5;
    int*p=0;
    // cout<<"pointer is"<<*p<<endl;
    p=&i;
    cout<<"address is"<<p<<endl;
    cout<<"value is"<<*p;
    int a=*p;
    a++;
    cout<<"a is"<<a<<endl;
    cout<<"p is"<<*p<<endl;
    cout<<"i is"<<i<<endl;
    *p++;
    cout<<"p is"<<*p<<endl;
    int *q=p;
    cout<<"p is"<<p<<" "<<"q is"<<q<<endl;

  


}
