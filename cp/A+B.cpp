#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> sum(vector<int> v){
    int size=v.size();
    vector<int> output(size);
    for(int i=0;i<size;i++){
        string s = to_string(v[i]);
        if (s.size() == 2) {
            output[i] = (s[0] - '0') + (s[1] - '0');
        }
    }
    return output;
}
int main(){
    int n;
   
    cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        int m;
 
        cin>>m;
        v[i]=m;
    }
    vector<int> ans ;
    ans=sum(v);
    for(int j=0;j<ans.size();j++){
        cout<<ans[j]<<endl;
    }
}