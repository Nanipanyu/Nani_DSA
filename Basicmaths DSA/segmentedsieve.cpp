#include<iostream>
#include<cmath>
using namespace std;
void segmentedsieve(int l,int h){
    int n=sqrt(h);
    bool isprime[n+1];
    for(int k=2;k<n+1;k++){
        isprime[k]=true;
    }
    // isprime[0]=isprime[1]=false;
    // int count=0;
    for(int i=2;i<n+1;i++){

        // int j=2;
        if(isprime[i]){
            for( int j=i*2;j<n+1;j=j+i){
                isprime[j]=false;
            }         

        }  
    }
    int L=h-l+1;
    bool prm[L];
    for(int d=0;d<L;d++){
        prm[d]=true;
    }

    for(int k=2;k<L;k++){
        if(isprime[k]){
            int start=max(k*k,(l+k-1)/k*k);
            for(int n=start;n<=h;n+=k){
                prm[n-l]=false;
            }       

    }
    }
    if(l==1){
        prm[0]=false;
    }
    else if(l==0){
        prm[0]=prm[1]=false;
    }
    for(int H=0;H<L;H++){
        if(prm[H]){
            cout<<H+l<<" ";
        }

    }
}


int main() {
    int L, R;
    std::cout << "Enter the range [L, R]: ";
    std::cin >> L >> R;

    segmentedsieve(L, R);

    return 0;
}
  