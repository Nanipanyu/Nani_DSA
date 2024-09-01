#include<iostream>
using namespace std;
int fct(int n){
    
    int num=1;
    for(int i=1;i<=n;i++){
        num=num*i;
    }
    return num;
}
int ncr(int n,int r){
    
    int result=fct(n)/(fct(r)*fct(n-r));

    return result;
}
int main(){
    int N;
    int R;
    cout<< "Enter  N";
    cin>> N;
    cout<< "Enter R";
    cin>> R;
    int answer=ncr(N,R);
    cout<<"answer is:"<<answer;

}


