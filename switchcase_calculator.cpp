#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int a,b;
    cout<< "Enter the value of a";
    cin>> a;

    cout<<"Enter the value of b";
    cin>> b;

    char c;
    cout<<"Enter the operation you want to perform";
    cin>> c;

    switch(c){
        case '+':cout<<a+b;
                break;
        case '-':cout<<a-b;
                break;
        case '*':cout<<a*b;
                break;
        case '/':cout<<a/b;
                break;
        case '%':cout<<a%b;
                break;                        
    }
    
    }
   


