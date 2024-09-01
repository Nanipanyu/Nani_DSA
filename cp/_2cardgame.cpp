#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"enter number of games"<<" ";
    cin>>n;
    vector<vector<int>> outer;
    for(int i=0;i<n;i++){
        vector<int> inner(4);
        cout<<"Enter sequence"<<endl;    
        int a,b,c,d;            
        cin >>a >> b >> c >> d;              
        inner={a,b,c,d};        
        outer.push_back(inner);
    }
    vector<int> ans;    
    for(int i=0;i<n;i++){
        int count=4;
        vector<int> sunit;
        vector<int> sachin;
        for(int j=0;j<2;j++){
            sunit.push_back(outer[i][j]);
            sachin.push_back(outer[i][j+2]);            
        }
        sort(sunit.begin(), sunit.end());
        sort(sachin.begin(), sachin.end());

        for(int k=0;k<2;k++){
            for(int l=0;l<2;l++){
                if(sunit[k]<sachin[l]){
                count++;
                }
                if(sunit[k]>sachin[l]){
                count--;
                }
            }
        }
        if(count==4 || count==8){
            ans.push_back(0);
        }
        if(count==0){
            ans.push_back(4);
        } 
        if(count==2){
            ans.push_back(2);
        }     

    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;    
    } 
}