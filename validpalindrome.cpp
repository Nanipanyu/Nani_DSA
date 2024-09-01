#include<iostream>
using namespace std;
bool validchar(char ch){
    if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z') ||(ch>='0'&& ch<='9')){
        return 1;
    }
    return 0;
}
char tolowercase(char ch){
    if((ch>='a' && ch <='z')||(ch>='0'&& ch<='9')){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
}


bool ispalindrome(string a){
    int S=0;
    int e=a.length()-1;
    int count=0;
    while(S<=e){
        if(a[S]!=a[e]){
            return 0;
        }
        S++;
        e--;
    }
    return 1;

    }

     
    


bool transform(string s){
    string temp="";
    for (int j=0;j<s.length();j++){
        if(validchar(s[j])){
            temp.push_back(s[j]);
        }
    }
    for(int i=0;i<temp.length();i++){
        temp[i]=tolowercase(temp[i]);
    }
    return(ispalindrome(temp));
}

int main(){
    string name;
    cout<<"Enter your string"<<" ";
    cin>>name;

    if(transform(name)){
        cout<<"it is a palindrome";
    }
    else{
        cout<<"it is not a palindrome";
    }

}