#include<iostream>
using namespace std;
void print(int *n){
    *n=*n+1;

}
int getsum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
    sum+=arr[i];
    }
    return sum;
}
int main(){
    int num[6]={1,2,3,4,5,6};
    cout<<getsum(num+3,3);

}
