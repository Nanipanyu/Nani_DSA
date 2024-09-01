#include<iostream>
using namespace std;
void reverse(char arr[]){
    if(arr[0]=='\0'){
        return;
    }
    int i=1;
    reverse(arr+1) ; 
    cout<<arr[0];  
}
int main(){
    char word[5];
    cout<<"Enter your word"<<" ";
    cin>>word;
    cout<<"your word is"<<" ";
    reverse(word);

    
}