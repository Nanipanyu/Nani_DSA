#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void maxheapify(vector<int> &arr,int n,int i){  // for zero based array(i.e elements start from 0 posn)
        int largest = i; // Initialize largest as root
        int left = 2 * i +1 ; // left(child)= 2*i 
        int right = 2 * i + 2; // right(child) = 2*i +1
        if(left>n && right>n){  //incase of a leaf node return(beacause leaf node=heap)
            return;
        }
        // assign largest as the index of its greatest child
        if(left<n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<n && arr[largest]<arr[right]){
            largest=right;
        }
        
        if(largest!=i){  // condition means its child is greater than 'i' (largest has been changed)
            swap(arr[i],arr[largest]); //swap their position
            maxheapify(arr,n,largest);  //check heap for the node which has been swapped and now is in child position
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector<int> heap;  //creating a new vector heap and pushing all ele of both a and b vectors in heap
        for(int i=0;i<n;i++){
            heap.push_back(a[i]);
        }
        for(int i=0;i<m;i++){
            heap.push_back(b[i]);
        }
        int size=heap.size();
        for(int j=(size/2)-1;j>=0;j--){
            maxheapify(heap,size,j);   //using heapify algo arranging the not leafnodes in their correct position
        }
        
        return heap;
    }
};