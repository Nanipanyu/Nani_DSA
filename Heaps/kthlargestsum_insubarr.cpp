#include<iostream>
#include<queue>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
	//	Given an array we have to get the sum of all subarrays of arr and find the kth largest sum among them

    //using minheap for the problem
	priority_queue<int,vector<int>,greater<int>> minheap;

    //traversing subarray for each element
	for(int i=0;i<arr.size();i++){
		int sum=0;
        // traversing within the subarray
		for(int j=i;j<arr.size();j++){
            //sum of subarrays
			sum+=arr[j];
			if(minheap.size()<k){ //pushing the first k sums in minheap(i.e if minheap.size()<k)
				minheap.push(sum);
			}
			else{
                //after filling minheap with kelements ,smallest ele(kth largest sum till then) will be on top , then only if the sum>heap,top pop the heap.top and insert sum, this way after all iteration u will have the kth largest ele at top of minheap 
				if(sum>minheap.top()){ 
					minheap.pop();
					minheap.push(sum);
				}
			}
		}
	}
	return minheap.top();
}