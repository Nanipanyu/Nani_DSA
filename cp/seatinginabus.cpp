#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter no of test case"<<" ";
    int n;
    cin>> n;
    for(int i=0;i<n;i++){
        cout<<"Enter no of elements in array"<<" ";
        int m;
        cin>> m;
        vector<int> seats;
        for(int j=0;j<m;j++){
            cout<<"Enter seat no"<< " ";
            int x;
            
            cin>> x;
            seats.push_back(x);
        }
        int ma=seats[0];
        int mi=seats[0];
        bool check=false;
        for(int k=1;k<m;k++){
            
            if(k==1){
                if(seats[k]==seats[k-1]+1 || seats[k]==seats[k-1]-1 ){
                    check=true;
                }
                else{
                    break;
                }
            }
            else{
                if((seats[k]<ma && seats[k]>mi) || seats[k]==ma+1 || seats[k]==mi-1){
                    check=true;
                }
                else{
                    check=false;
                    break;
                }
            }
            ma=max(ma,seats[k]);
            mi=min(mi,seats[k]);
        } 
        if(check==false){
            cout<<"NO"<<endl;
        }   
        else{
            cout<<"YES"<<endl;
        }    
    }
}