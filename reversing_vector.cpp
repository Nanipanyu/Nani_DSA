#include<iostream>
#include<vector>
using namespace std;
// making a vector func
vector<int> reverse(vector<int> v,int n){
    int s=n, e=v.size()-1;
    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}

void print(vector<int> v){
    for(int i:v){
        cout<<i<<" ";
    }
    cout<< endl;
}
int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(9);
    v.push_back(10);
    v.push_back(5);
    v.push_back(34);

    vector<int> ans=reverse(v,3);
    print(ans);
     return 0;


}