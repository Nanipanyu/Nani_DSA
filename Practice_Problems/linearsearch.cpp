#include<iostream>
using namespace std;
bool search(int sus[],int size, int key){
    for(int i=0;i<size;i++){
        if(key==sus[i]){
            return 1;
        }

    }
    return 0;
}

int main(){
    int num[7]={1,-5,22,7,-89,0,8};
    int key;
    cout<<"Enter your no";
    cin>>key;
    bool found=search(num,7,key);
    cout<<found;


}