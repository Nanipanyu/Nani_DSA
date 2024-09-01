#include<iostream>
using namespace std;
int main(){
    int num[11]={22,34,54,67,34,77,22,67,2,2,34};
    int sas[11];
    for(int i=0;i<11;i++){
    
        for(int j=i;j<11;j++){
            if(j!=i && num[i]==num[j]){
                cout<<num[i]<<" ";
                break;
                
                    }
                    
                }
    }
}
    

