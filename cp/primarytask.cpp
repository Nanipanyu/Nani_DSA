#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin>> a;
        string s=to_string(a);
        if(s[0]=='1' && s[1]=='0'){
            if(s[2]-'0'>=2 || (s[2]-'0'<2 && s[2]-'0'!=0 && s.size()>3)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        else{
            cout<<"No"<<endl;
        }
    }
}