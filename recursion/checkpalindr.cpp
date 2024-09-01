#include<iostream>
#include<string>
using namespace std;
bool chkpalindrome(string n,int i,int j){
    if(i>j){
        return true;
    }
    if(n[i]!=n[j]){
        return false;
    }
    i++;
    j--;
    bool ans=chkpalindrome(n,i,j);
    return ans;
    
}
int main(){
    string name;
    cout<<"Enter your string"<<" ";
    cin>>name;
    if(chkpalindrome(name,0,name.length()-1)){
        cout<<"it is a palindrome";
    }
    else{
        cout<<"it is not a palindrome";
    }

}
