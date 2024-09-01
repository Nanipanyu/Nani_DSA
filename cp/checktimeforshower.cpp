#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter no. of test case"<< endl;
    int t;
    cin>>t;    
    vector<vector<vector<int>>> outer;
    for(int i=0;i<t;i++){
        vector<vector<int>> inner;
        cout<<"Enter n s m"<<" ";
        int n,s,m;
        cin>> n >> s >> m;
        vector<int> nsm;
        nsm={n,s,m};
        inner.push_back(nsm);
        for(int j=0;j<n;j++){
            cout<<"Enter intervals"<<" ";
            int a,b;
            cin>>a>>b;
            vector<int> ab;
            if(a,b>=0  && a,b<m){
                ab={a,b};
            }
            inner.push_back(ab);
        }
        outer.push_back(inner);
    }
     for(int i=0;i<t;i++){
        bool check=false;
        for(int j=0;j<=outer[i][0][0];j++){
            if(j==0){
                int a=outer[i][j+1][0];
                if(a>=outer[i][0][1]){
                    check=true;
                    break;
                }
            }
            else if(j==outer[i][0][0]){
                int a=outer[i][j][1];
                if(outer[i][0][2]-a>=outer[i][0][1]){
                    check=true;
                    break;
                }
            }
            else{
                int a=outer[i][j+1][0];
                int b=outer[i][j][1];
                if(a-b>=outer[i][0][1]){
                    check=true;
                    break;
                }
            }            
        }
        if(check==true){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
     }

}
