#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<< "Enter your character";
    cin>> ch;
    if(ch>='1' && ch<='9'){
        cout<< "This ia numeric";
    }
    else if(ch>='a' && ch<='z'){
        cout<< "This is lower case";
    }
    else if( ch>'A' && ch<'Z'){
        cout<< "This is upper case";
    }
        

    }

