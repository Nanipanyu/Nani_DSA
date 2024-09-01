#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0){
        return 1;
    }
    int small=factorial(n-1);
    int bigger=n*small;

    return bigger;
    
}
int main (){
    int n;
    cout<<"enter your integer"<<" ";
    cin>>n;
    cout<<factorial(n);

}