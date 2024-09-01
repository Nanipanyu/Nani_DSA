#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else if(b>a){
            b=b-a;
        }
        else{
            return a;
        }
    }    
}

int main()
{
    int t ;
    cin >> t;
    while (t--)
    {
        vector<int> v(2);
        cin >> v[0] >> v[1];
        vector<int> nums;
        int size=v[1]-v[0];
        for(int i=v[0];i<=size;i++){
            nums.push_back(i);
        }
        int maxop=0;
        int s=nums.size()/2;
        if(size+1<3){
            cout<<0<<endl;
        }
        else{
            for(int i=0;i<s;i=i+2){
                int count=i+2;
                while(count<s){
                    if((gcd(nums[i],nums[count])==1) && (gcd(nums[i+1],nums[count])==1)){
                        maxop++;
                        nums.erase(nums.begin()+i);
                        nums.erase(nums.begin()+i+1);
                        nums.erase(nums.begin()+count);
                    }
                    else if(count+1<=size && (gcd(nums[i],nums[count+1])==1) && (gcd(nums[i+1],nums[count+1])==1)){
                        maxop++;
                        nums.erase(nums.begin()+i);
                        nums.erase(nums.begin()+i+1);
                        nums.erase(nums.begin()+i+3);
                    }
                    count=+2;
                }
            }
            cout<<maxop<<endl;
        }

    }
    return 0;
}