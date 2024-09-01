#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t ;
    cin >> t;
    while (t--)
    {
        vector<int> segment;
        for(int i=0;i<2;i++){
            int l,r;
            cin>> l>> r;
            segment.push_back(l);
            segment.push_back(r);
        }
        if(segment[1]<segment[2] || segment[0]>segment[3]){
            if(segment[1]<segment[2]){
                cout<<segment[2]-segment[1]<<endl;
            }
            else{
                cout<<segment[0]-segment[3]<<endl;
            }
        }
        else if(segment[0]==segment[2] && segment[1]==segment[3]){
            cout<<segment[1]-segment[0]<<endl;
        }
        else if((segment[0]==segment[2] && segment[1]!=segment[3]) || (segment[0]!=segment[2] && segment[1]==segment[3])){
            int sub=max((segment[1]-segment[0]),(segment[3]-segment[2]));
            int diff=0;
            if(segment[0]==segment[2] && segment[1]!=segment[3]){
                if(segment[1]>segment[3]){
                    diff=segment[1]-segment[3];
                }
                else{
                    diff=segment[3]-segment[1];
                }
            }
            else{
                if(segment[0]>segment[2]){
                    diff=segment[0]-segment[2];
                }
                else{
                    diff=segment[2]-segment[0];
                }
            }            
            cout<<sub-diff+1<<endl;
        }
        else if((segment[0]<segment[2]  && segment[0]<segment[3] && segment[1]>segment[2] && segment[1]>segment[3]) || (segment[2]<segment[0]  && segment[2]<segment[1] && segment[3]>segment[0] && segment[3]>segment[1])){
            int mini=*min_element(segment.begin(),segment.end());
            if(segment[0]==mini){
                cout<<segment[3]-segment[2]+2<<endl;
            }
            else{
                cout<<segment[1]-segment[0]+2<<endl;
            }
        }
        else if((segment[0]<segment[2] && segment[2]==segment[1]) || (segment[2]<segment[0] && segment[0]==segment[3])){
            cout<<2<<endl;
        }
        else{
            if(segment[3]>segment[1]){
                cout<<segment[1]+1-segment[2]<<endl;
            }
            else{
               cout<<segment[3]+1-segment[0]<<endl; 
            }
        }
    }
    return 0;
}