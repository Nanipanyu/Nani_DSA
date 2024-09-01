#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mainCode(){
    int n=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
}

int main()
{
    int t ;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);

        if(n%2==0){
            cout<<-1<<endl;
        } 
        else{
            int first=n/2;
            for(int i=0;i<first;i++){                
                v[i]=n-i;
            }
            for(int j=first;j<n;j++){                
                v[j]=j-first+1;
            }
            for(int k=0;k<n;k++){
            cout<<v[k]<<" ";
            }
            cout<<endl;
        }         
    }
    return 0;
}