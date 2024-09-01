#include<iostream>
using namespace std;
int main(){
    int num[6]={1,3,5,72,9,0};
    for(int i=0;i<6;i=i+2){
        int s=num[i];
        num[i]=num[i+1];
        num[i+1]=s;
        cout<<num[i];

    }
    cout<<"num is";
    for(int j=0;j<6;j++){
        cout<<num[j]<<" ";    


    }
}