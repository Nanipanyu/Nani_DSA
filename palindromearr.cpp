#include<iostream>
using namespace std;
char lowercase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
}
void check(char ch[]){
    int count=0;
    for(int i=0;ch[i]!='\0';i++){
        count++;
    }
    int s=0;
    int e=count-1;
    int d=0;
    while(s<e){
        if(lowercase(ch[s])!=lowercase(ch[e])){
            d++;

        }
        s++;
        e--;
    }
    if(d==0){
        cout<<"it is a palindrome";
    }
    else{
        cout<<"it is not a palindrome";
    }


}
int main(){
    char name[10];
    cout<<"Enter your character"<<endl;
    cin>>name;
    check(name);

}