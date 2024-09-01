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
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        if(v.size()>2){
            cout<<"NO"<<endl;
        }
        else if(v.size()==1){
            cout<<"YES"<<endl;
        }
        else if(v.size()==2){
            if(v[0]-v[1]>1 || v[1]-v[0]>1){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}