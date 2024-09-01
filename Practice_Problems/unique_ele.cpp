#include<iostream>
using namespace std;
int main(){
    int num[10]={22,34,54,67,34,77,22,67,2,2};
    int jug[10];
    int A=0;
    int B=0;
    for(int i=0;i<10;i++){
        B=0;
        if(i==0){
            for(int j=1;j<10;j++){
                if(num[i]==num[j]){
                    A=1;
                    break;
                }
            }
            if(A==0){
                cout<<num[i]<<" "<<"is unique";
            }
        }
        else{
            for(int j=0;j<10;j++){
                
                if(j!=i && num[i]==num[j]){
                    B=1;
                    break;
                }
                
            }
            if(B==0){
                cout<<endl<<num[i]<<" yes it is unique";
            }    


    }
}
}