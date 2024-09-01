#include<iostream>
using namespace std;
int main(){
    int num[6]={-1,3,4,2,5,21};
    for(int i=0;i<6/2;i++){
        int s=num[i] ;
        num[i]=num[5-i] ;
        num[5-i]=s;

    }
    // in c++ if you try to print an arrray using the name of the array ,the address of the first element in array is printed
    for(int j=0;j<=5;j++){

    
    cout<<num[j]<<" ";
}
cout<<endl;
    // int num[6]={-1,3,4,2,5,21};
    int s=0;
    int e=5;
    int i=1;
    while(s<=e){
        swap(num[s],num[e]);
        s=s+i;
        e=e-i;
        

    }
    for(int j=0;j<=5;j++){

    
    cout<<num[j]<<" ";
}



}
