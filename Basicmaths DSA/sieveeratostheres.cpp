#include<iostream>
using namespace std;

int countprime(int n){
    bool isprime[n];
    for(int k=2;k<n;k++){
        isprime[k]=true;
    }
    // isprime[0]=isprime[1]=false;
    int count=0;
    for(int i=2;i<n;i++){

        // int j=2;
        if(isprime[i]){
            for( int j=i*2;j<n;j=j+i){
                isprime[j]=false;
            }
            count++;

        }


    }
    return count;

}
int main(){
    int p;
    cout<<"Enter your number"<<" ";
    cin>>p;
    cout<<"no of primes between this no is"<<" "<<countprime(p);
}