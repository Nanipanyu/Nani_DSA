#include<iostream>
using namespace std;
int main(){
    int a;
    cout<< "Enter your integer";
    cin>> a;
    int temp=a;
    int sum=0;
    while(a!=0){
       sum=sum+(a%10);
        a=a/10;
        }  
    cout<<"sum:"<< sum<<","<<" ";
    int b=temp;
    int mult=1;
     while(b!=0){
        mult = mult * (b%10);
        b=b/10;
        }  
    cout<<"mult:"<< mult<<","<<" ";
    int sub=sum-mult;
    cout<< "sub of mult and sum:"<<sub;
      
         
    }
     

    
        
    
     

    

        
     

    

    
