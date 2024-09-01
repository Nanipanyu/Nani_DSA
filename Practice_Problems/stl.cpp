#include<iostream>
#include<array>
#include<set>
using namespace std;
int main(){
int basic[3]={1,2,3};
array<int,4> a={1,2,3,4};
int size=a.size();

for(int i=0;i<size;i++){
    cout<<a[i]<<endl;

}
cout<<"leement at second index"<<a.at(2)<<endl;
cout<<"empty or not"<<a.empty()<<endl;
cout<<"first element"<<a.front()<<endl;
cout<<"last element"<<a.back()<<endl;  

set<int>s;
s.insert(2);
s.insert(5);
s.insert(7);
s.insert(0);
s.insert(1);
for(auto i:s){
    cout<<i<<" ";
}
cout<<endl;
cout<<"s is present or not"<<s.count(5)<<endl;
set<int>::iterator it=s.find(7);
cout<<"checking"<<*it<<endl;






}

