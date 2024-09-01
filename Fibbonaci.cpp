#include<iostream>
using namespace std;
int main(){
    int a=0;
    int b=1;
    int c;
    cout<<"Enter a nmuber";
    cin>>c;
    int sum=0;
    cout<<a<<" "<<b<<" ";
    for(int i=0; i<=c;i++ ){
        
        sum=a+b;
         cout<<sum<<" ";
        a=b;
        b=sum;
        


    }
}
