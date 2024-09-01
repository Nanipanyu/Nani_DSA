#include<iostream>
#include<vector>
#include<array>
// #include<algorithm>
using namespace std;
vector<int> reverse(vector<int> v){
    int s=0;
    int e=v.size()-1;
    while(s<e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}
void sumofarray(int arr1[],int n,int arr2[],int m){
    int i=n-1;
    int j=m-1;
    vector<int> ans;
    int carry=0;
    int sum=0;
    int value=0;
    while(i>=0 && j>=0){
        sum=arr1[i]+arr2[j]+carry;
        value=sum%10;
        carry=sum/10;
        ans.push_back(value); 
        i--;
        j--;       
    }
    while(i>=0){
        sum=arr1[i]+carry;
        value=sum%10;
        carry=sum/10;
        ans.push_back(value); 
        i--;
         

    }
    while(j>=0){
        sum=arr2[j]+carry;
        value=sum%10;
        carry=sum/10;
        ans.push_back(value);   
        
        j--;     
    
    }
    while(carry!=0){
        sum=carry;
        value=sum%10;
        carry=sum/10;
        ans.push_back(carry);
    }
    for(int i:reverse(ans)){
        cout<<i<<" ";
    }
    
    
}
 int main(){
    int num[3]={9,6,8};
    int tum[2]={3,5};
    sumofarray(num,3,tum,2);
 }

