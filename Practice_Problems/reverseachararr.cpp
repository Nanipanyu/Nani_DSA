#include<iostream>
using namespace std;
void reverse(char ch[]){
    int count=0;
    for(int i=0;ch[i]!='\0';i++){
        count++;
    }
    for(int j=0;j<=count/2;j++){
        swap(ch[j],ch[count-j-1]);
    }
    cout<<ch;

}
int main(){
    char name[10];
    cout<<"Enter your character"<<endl;
    cin>>name;
    reverse(name);

}