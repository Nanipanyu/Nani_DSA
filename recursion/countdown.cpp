#include<iostream>
using namespace std;
void count(int n){
    // base case
    if(n==0){
        return;
    }
    // processing
    cout<<n<<" ";
    // recursive call
    count(n-1);

}
int main(){
    int n;
    cout<<"enter your integer"<<" ";
    cin>>n;
    count(n);
}
