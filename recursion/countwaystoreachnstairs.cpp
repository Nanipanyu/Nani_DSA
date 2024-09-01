#include<iostream>
using namespace std;
int stairs(int n ){
    if(n<0){
        return 0;
    }
    // no.of ways he can reach 0 stairs is by jumping on itself
    if(n==0){
        return 1;
    }
    //no of ways to reach the nth step = summation of number of steps from (nth-2) and (nth -1)
    // you can at max jump 2 stairs
    int relation=stairs(n-1)+stairs(n-2);
    return relation;


}
int main(){
    int n;
    cout<<"enter no. of stairs"<<" ";
    cin>>n;
    cout<<"no. of ways you can reach the stairs"<<stairs(n);
    

}