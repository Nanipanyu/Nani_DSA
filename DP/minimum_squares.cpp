#include<iostream>
using namespace std;
#include<cmath>
int count(int n){
    if(n==0){
        return 0;
    }
    int step=count(n- pow(floor(sqrt(n)), 2));
    return step+1;
}

int MinSquares(int n) {
    double root=sqrt(n);

    if(root==floor(root)){
        return 1;
    }
    int ans=count(n);
    return ans;
}

int main(){
    int n=7;
    cout<<MinSquares(n)<<endl;
    return 0;
}