#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> resolve(vector<int> vec,int k){
    vector<int> window(k);
    vector<int> ans;
    for(int i=0;i<k;i++){
        window[i]=vec[i];
    }
    for(int j=0;j<vec.size()-k+1;j++){
        auto maxIt=max_element(window.begin(),window.end());
        auto minIt=min_element(window.begin(),window.end());
        int maxele=*maxIt;
        int minele=*minIt;
        cout<<"ans is"<<" "<<maxele<<" "<<minele<<endl;
        ans.push_back(maxele+minele);
        window.erase(window.begin());
        if(j+k<vec.size()){
            window.push_back(vec[j+k]);
        }
    }
    return ans;
}
int resolvewithqueue(vector<int> vec,int k){
    vector<int> ans;
    deque<int> maxi;
    deque<int> mini;
    for(int i=0;i<k;i++){
        while(!maxi.empty() && vec[maxi.back()] <= vec[i] ){
            maxi.pop_back();
        }
        while(!mini.empty() && vec[mini.back()] >= vec[i] ){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans2=0;
    ans2= vec[maxi.front()]+vec[mini.front()];
    for(int i=k;i<vec.size();i++){
        while(!maxi.empty() && i-maxi.front() >=k ){
            maxi.pop_front();
        }
        while(!mini.empty() && i-mini.front() >=k ){
            mini.pop_front();
        }
        //addition
        while(!maxi.empty() && vec[maxi.back()] <=vec[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && vec[mini.back()] >=vec[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        ans2+= vec[maxi.front()]+vec[mini.front()];
    }
    return ans2;   

}
int main(){
    vector<int> vec={2, 5, -1, 7, -3, -1, -2};

    vector<int> ans=resolve(vec , 4);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    int ansnew=resolvewithqueue(vec , 4);
    cout<<"ans is"<<" "<<ansnew<<endl;

}
