#include<iostream>
#include<string>
using namespace std;
int main(){
    cout<<"Enter no of test case"<<" ";
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Enter your string s"<<" ";
        string s;
        cin>>s;
        cout<<"Enter your sub string t"<<" ";
        string t;
        cin>>t;

        int tsize=t.size();
        int ssize=s.size();
        int ind=0;
        int count=0;
        for(int j=0;j<tsize;j++){
            while(ind<ssize){
                if((t[j]==s[ind]) || (s[ind]=='?')){
                    count++;
                    ind++;
                    break;
                }
                ind++;
            }
            if(ind==ssize || count==tsize){
                break;
            }
        }
        if(count==tsize){
            cout<<"YES"<<endl;
            ind=0;
            for(int k=0;k<ssize;k++){
                if(s[k]==t[ind] ){
                    ind++;
                }
                else if(s[k]=='?' ){
                    s[k]=t[ind];
                    ind++;
                }
                
                if(ind==tsize){
                    ind--;
                }
            }
            cout<<s<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

}