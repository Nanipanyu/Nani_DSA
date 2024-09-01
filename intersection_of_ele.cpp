#include<iostream>
using namespace std;
int main(){
      int num[11]={22,34,54,67,34,77,22,67,2,2,34};
      int sas[11]={22,56,34,1,5,7,42,77,2,23,21};
      for(int i=0;i,11;i++){
        for(int j=0;j<11;j++){
            if(num[i]==sas[j]){
                cout<<num[i]<<" ";                     
            }
        }

      }
}