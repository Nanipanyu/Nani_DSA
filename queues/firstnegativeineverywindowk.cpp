#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],
    long long int N, long long int K) {
        vector<long long> ans;
        queue<int> q;  
        for(int j=0;j<K;j++){  //first k size element index to be put in queue if negative
            if(A[j]<0){
                q.push(j);
            }
        }
        for(  int i=0;i<N-K+1;i++){ //iterate for each window
            if(!q.empty()){
                ans.push_back(A[q.front()]);  //if there is a negative element in the window then the q.front will be giving the first negative no. 
            }
            else{
                    ans.push_back(0) ;  // if queue is emmpty, i.e no negative elements then insert 0 fro that window
                }
                                                    
            if(i>=q.front() && !q.empty()){ //pop the previous element while moving into a new window but if the elment inside can be used for the next window(i.e that elements also come in the next window(i>=q.front()) then dont pop)
                q.pop();
            }
            if(A[i+K]<0 && i+K<N){ //push the element of next window while moving to next window if negative
                q.push(i+K);
            }
        }
        return ans;   
                                                 
 }