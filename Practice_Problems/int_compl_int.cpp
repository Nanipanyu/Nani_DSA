#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int a;
    cout<<"Enter your integer";
    cin>> a;
    
    int sum=0;
    int c=0;
    while(a>1){
        if(a%2==0){
            sum=sum+pow(2,c);
            c++;
            }
        else{
            c++;
        }
        a=a/2;
    }
        
        
    cout<< sum;        

        
    
        

    }
       
        
