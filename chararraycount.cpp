#include<iostream>
using namespace std;
int getlength(char ch[]){
        int count=0;

    for(int i=0;ch[i]!='\0';i++){
        count++;
    }
    return count;

}
int main(){
    char name[10];
    cout<<"Enter your character";
    
    cin>>name;
    
    cout<<"Name is"<<" ";
    cout<<name<<endl;

    cout<<"count is"<<getlength(name);
    

}