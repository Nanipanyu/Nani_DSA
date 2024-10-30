#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class solution{ 
public:
    // Function to return the minimum cost of connecting the ropes.
    void minheapify(vector<long long>& arr,int n,int i){
        int smallest = i; // Initialize largest as root
        int left = 2 * i +1 ; // left(child)= 2*i 
        int right = 2 * i + 2; // right(child) = 2*i +1
        if(left>n && right>n){  //incase of a leaf node return(beacause leaf node=heap)
            return;
        }
        // assign largest as the index of its greatest child
        if(left<n && arr[smallest]>arr[left]){
            smallest=left;
        }
        if(right<n && arr[smallest]>arr[right]){
            smallest=right;
        }
        
        if(smallest!=i){  // condition means its child is greater than 'i' (largest has been changed)
            swap(arr[i],arr[smallest]); //swap their position
            minheapify(arr,n,smallest);  //check heap for the node which has been swapped and now is in child position
        }
}
    
    
    long long minCost(vector<long long>& arr) {
        // Your code here
        int size=arr.size();
        for(int i=(size/2)-1;i>=0;i--){  //minimum cost will be achieved by adding the numbers from increasing order(smallest to biggest)
            minheapify(arr,size,i);  //converting the arr into minheap
        }
        int ans=0;
        int prev=arr[0];
        for(int i=1;i<size;i++){ //finding cost
            prev=prev+arr[i];
            ans=ans+prev;
        }cout<<endl;
        
        return ans;
    }
};


//using priority queue

class Solution {
public:
    long long minCost(vector<long long>& arr) {
        // Min-heap to store all rope lengths
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(arr.begin(), arr.end());
        
        long long totalCost = 0;
        
        // Combine ropes until one rope remains
        while (minHeap.size() > 1) {
            // Take the two smallest ropes
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();
            
            // Cost to combine them
            long long cost = first + second;
            totalCost += cost;
            
            // Push the combined rope back into the heap
            minHeap.push(cost);
        }
        
        return totalCost;
    }
};