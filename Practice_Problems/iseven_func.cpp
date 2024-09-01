#include<iostream>
using namespace std;
bool iseven(int num){
    if(num&1){
        return 0;
    }
     return 1;
      
    }
int main(){
    int a;
    cout<< "Enter is your number";
    cin>> a;
    if(iseven(a)){
        cout<<"number is even";
    }
    else{
        cout<<"no. is odd";
    }
}    