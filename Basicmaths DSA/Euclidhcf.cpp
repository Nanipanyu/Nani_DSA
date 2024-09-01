#include<iostream>
using namespace std;
int hcf(int n,int m){
    if(n==0){
        return m;              
    }
     if(m==0){
        return n;              
    }
    while(n!=m){
        if(n==m){
            return n;
        }
        else if(n>m){
            n=n-m;
        }
        else{
            m=m-n;
        }
    }

}
int main(){
    int a,b;
    cout<<"Enter your no.'s"<<" ";
    cin>>a>>b;
    // cin>>b;

    cout<<"your hcf is"<<hcf(a,b);
    
}