#include<iostream>
using namespace std;
void digits(int n){
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    // base case
    if(n==0){
        return;
    }
    int ans=n%10;
    // recursive relation and processing
    n=n/10;
    digits(n);
    cout<<arr[ans]<<" ";    
}
int main(){
    int n;
    cout<<" Enter your number"<<" ";
    cin>>n;
    digits(n);
}