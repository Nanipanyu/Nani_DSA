#include<iostream>
using namespace std;
// int main(){
//     int num[7]={45,78,1,6,34,15,2};
//     for(int i=0;i<6;i++){
        

//         for(int j=i+1;j<7;j++){
//             if(num[j]<num[i]){
//                 swap(num[i],num[j]);


//             }           

//         }
//         cout<<num[i]<<" ";
//         }
//         cout<<num[6];
//     }

int main(){
    int num[7]={45,78,1,6,34,15,2};
    for(int i=0;i<6;i++){
        int a=i;
        for(int j=i+1;j<7;j++){
            if(num[j]<num[a]){
                a=j;

            }
        }
        swap(num[i],num[a]);
        cout<<num[i]<<" ";
    }
    cout<<num[6];
}    
