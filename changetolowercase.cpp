#include<iostream>
using namespace std;
char conversioncase(char ch){
    if(ch>='a'&&ch<='z'){
        char temp1=ch-'a'+'A';
        return temp1;
    }
    else{
        char temp2=ch-'A'+'a';
        return temp2;
    }
}


int main(){
    char a;
    cout<<"Enter your char"<<endl;
    cin>> a;
    cout<<"your conversion"<<" "<<conversioncase(a);



}