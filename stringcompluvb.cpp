#include<iostream>
#include<cstring>
#include<algorithm>
#include<array>
using namespace std;
void compress(char num[]){
    int i=0;
    int ans=0;
    int e=strlen(num)-1;
    while(i<e){
        int j=i+1;
        while(j<e && num[i]==num[j]){
            j++;
        }
        num[ans++]=num[i];
        int count=j-i;
        if(count>1){
            string cnt=to_string(count);
            for(char ch:cnt){
                num[ans++]=ch;
            }
        }
        i=j;

    }
    // int E=strlen(num);

    // for(int k=0;k<E;k++){
        cout<<num<<" ";
    // }
}
int main(){
    char ch[7];
    cout <<"Enter your character"<<" ";
    cin>>ch;
    compress(ch);
}