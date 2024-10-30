#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    void insert(vector<int> &arr,int data,int &size){
        // size=size+1;
        int index=size;
        arr[index]=data;
        size++;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void heapify(vector<int> &arr,int n,int i){
        int largest = i; // Initialize largest as root
        int left = 2 * i ; // left(child)= 2*i 
        int right = 2 * i + 1; // right(child) = 2*i +1
        if(left>n && right>n){  //incase of a leaf node return(beacause leaf node=heap)
            return;
        }
        // assign largest as the index of its greatest child
        if(left<=n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=n && arr[largest]<arr[right]){
            largest=right;
        }
        
        if(largest!=i){  // condition means its child is greater than 'i' (largest has been changed)
            swap(arr[i],arr[largest]); //swap their position
            heapify(arr,n,largest);  //check heap for the node which has been swapped and now is in child position
        }
    }
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        vector<int> heap(k+1);  //create a max heap of size k+1  ,+1 for 1-based indexing

        heap.push_back(-1);
        int size=1;
        for(int i=0;i<k;i++){ //pushing the first k elements of arr in heap and arranging it in maxheap using insert
            insert(heap,arr[i],size); 
        }
        size--;
        for(int i=k;i<arr.size();i++){  //for the remaining ele in arr (k+1 onwards ele), we compare each ele with heap top element(i.e its biggest ele)
            if(arr[i]<heap[1]){  //if(arr[k_onwards] ele is smaller than we replace it with heap top ele, st arr[i]=new heap top ele)
                heap[1]=arr[i];
                heapify(heap,size,1); //then arranging it to its correct position if not in correct posn
            }
        }
        //finally top ele in heap will be the kth smallest ele in arr;
        return heap[1]; 
    }
};