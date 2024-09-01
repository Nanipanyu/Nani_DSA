#include<iostream>
#include <math.h>

using namespace std;
int search(int x){
    int num[x+1];
    int s=0;
    int e=x;
    int mid=s+(e-s)/2;
    
    for(int i=0;i<x;i++){
        num[i]=i;
        
    }
    while(s<=e){
        if((mid*mid)==x){
            break;
            

            
        } 
        else if((mid*mid)<x){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;

    }
    if((mid*mid)>x){
        return (mid-1);
    }
    else{
        return mid;
    }

}




double more_precise(int n, int b){
    double ans=search(b);
    double a=0.1;
    double c=((ans+a)*(ans+a));

    

    for(int i=0;i<n;i++){
        if(c<b){
            while(c<b){
                a=a+0.1;            

                c=(ans+a)*(ans+a);


            }
            ans=c/(ans+a-1/10);   
        }
        a=a/(10);
        ans=ans+a;
        c=((ans+a)*(ans+a));
        


    }
    return c;    

}

int main(){
    int b;
    int f;
    cout<<"whose square do you want"<<endl;

    cin>>b;
    cout<<"upto what decimals"<<endl;
    cin>>f;

    cout<<more_precise(f,b);

}

