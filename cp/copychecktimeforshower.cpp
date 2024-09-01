#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int i=0;i<t;i++){
        vector<vector<int>> inner;
        int n,s,m;
        cin>> n >> s >> m;
        vector<int> nsm;
        nsm={n,s,m};
        inner.push_back(nsm);
        for(int j=0;j<n;j++){
            int a,b;
            cin>>a>>b;
            vector<int> ab;
            if(a>=0 && b>=0  && a<=m && b<=m){
                ab={a,b};
            }
            inner.push_back(ab);
        }   
        // bool check=false;
        int mat=inner[1][0];
        int shower=inner[0][1];
        for(int j=1;j<inner[0][0];j++){                        
            int ans=inner[j+1][0]-inner[j][1];
            mat=max(ans,mat);                       
        }
        int ans=inner[0][2]-inner[n][1];
        mat=max(mat,ans);
        if(mat>=shower){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
     }
}


