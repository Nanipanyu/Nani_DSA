#include<iostream>
#include<vector>
#include<stack>
#include <climits>
using namespace std;
class Solution{
private:
    vector<int> nextsmallestint(vector<int> arr,int n){
    stack<int> st;
    //intitializing stack with -1;
    st.push(-1);
    vector<int> result(n);
    n--;
    
    while(n>=0){
        while(st.top()!=-1 && arr[st.top()]>=arr[n]) {
            st.pop();
        } 
        result[n]=st.top();
        st.push(n);  
        n--;                 
    }
    return result;
    }

    vector<int> prevsmallestint(vector<int> arr,int n){
    stack<int> st;
    //intitializing stack with -1;
    st.push(-1);
    vector<int> result(n);
    int i=0;    
    while(i<n){
        while(st.top()!=-1 && arr[st.top()]>=arr[i]) {
            st.pop();
        } 
        result[i]=st.top();
        st.push(i);  
        i++;                 
    }
    return result;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next(n);
        next=nextsmallestint(heights,n);
        vector<int> prev(n);
        prev=prevsmallestint(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;            
            int newarea=l*b;
            area=max(area,newarea);            
        }
        return area;        
    }
    
//     vector<int> addVectors(vector<int>& vec1,vector<int>& vec2) {

//         vector<int> result(vec1.size());
//         for (int i = 0; i < vec1.size(); i++) {
//             if(vec2[i]==0){
//                 vec1[i]==0;
//             }
//             result[i] = vec1[i] + vec2[i];
//         }
    
//         return result;
// }
     
  public:
    int maxArea(int M[][4], int n, int m) {
        // Your code here
        // stack<vector<int>> s;
        // stack<vector<int>> c;
        // // vector<int> length;
        // for(int i=0;i<n;i++){
        //     vector<int> row;
        //     for(int j=0;j<m;j++){
        //         row.push_back(M[i][j]);
        //     }
        //     s.push(row);
        //     c=s;
    
        //     histogram=s.top();
        //     s.pop();
        //     while(!s.empty()){
        //          histogram=addVectors(histogram,s.top());
        //          s.pop();
        //      }
        //     int newarea=largestRectangleArea(histogram);
        //     area=max(area,newarea);
        //     s=c;
        //   }
        int area=INT_MIN;
        vector<int> histogram(m); //making a vector to make histogram as we move down the rows        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) { //for each row we make a histogram vector by adding all the previous rows to calculate the max rectangle possible by histogram
                if (M[i][j] == 0) {  
                    histogram[j] = 0;  //if a element of row has 0 values then a reactangle cannot be contributed form that side so set its histogram val to 0
                } else {
                    histogram[j] += M[i][j];  //if  element of rows are 1 then keep adding the corresponding col values of previous rows
                }
            }
            int newarea = largestRectangleArea(histogram); //find the largest rectangle possible from the histogram using largestrectangleinhistogram code
            area = max(newarea, area);  //return the max area among all histograms as we move to all rows;
        }       
        return area;
        
    }
};
int main() {
    Solution sol;
    int M[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };
    int result = sol.maxArea(M, 4, 4);
    cout << "Max Area: " << result << endl; // Expected Output: 8
    return 0;
}