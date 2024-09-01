#include <iostream>
#include <vector>
#include<map>
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        map<int,int>count;
        int maxi=-1;
        for(int j=0;j<n;j++){
            count[arr[j]]++;
            maxi=max(maxi,count[arr[j]]);
        }
        cout<<n-maxi<<endl;        
    }
    return 0;
}