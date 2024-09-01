#include<iostream>
using namespace std;
int main(){
    int x=0;
    int y=1;
    int a;
    cout<<"a is";
    cin>> a;
    int b=0;
    for(int i=0;i<(a);i++){
        if(a==1 ){
            cout<<'0';
            break;
        }
        else if(a==2){
            cout<<'1';
            break;
        }
    
        else{
            b=x+y;
            x=y;
            y=b;
        }    

        } 
    cout<<"b is"<<b;       
        
        
        
        
    
       
    

}

