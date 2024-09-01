#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int x ,y ,k;
        cin>>x>>y>>k;
        int xk=x*k;
        int yk=y*k;
        int sumx =0;
        int sumy=0;
        for(int j=0;j<k;j++){  
            if(j<k-1){
                cout<<j<<" "<<j+k<<" "<<endl;
                sumx=j+sumx;
                sumy=j+k+sumy;
            }
            else{
                cout<<xk-sumx<<" "<<yk-sumy<<" "<<endl;
            }
        }           
    }
}