#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;
//To find the max possible right side of breadth for a height of histogram bar (next)
    vector<int> nextsmallestint(vector<int> arr, int n) {
        stack<int> st;
        // Initializing stack with -1;
        st.push(-1);
        vector<int> result(n);
        n--;

        while (n >= 0) {
            while (st.top() != -1 && arr[st.top()] >= arr[n]) {
                st.pop();
            }
            result[n] = st.top();
            st.push(n);
            n--;
        }
        return result;
    }

//To find the max possible left side of breadth for a height of histogram bar (prev)
    
    vector<int> prevsmallestint(vector<int> arr, int n) {
        stack<int> st;
        // Initializing stack with -1;
        st.push(-1);
        vector<int> result(n);
        int i = 0;
        while (i < n) {
            while (st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            result[i] = st.top();
            st.push(i);
            i++;
        }
        return result;
    }


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextsmallestint(heights, n); //Vector for Getting the index of next smallest integer histogram bracket to help find the max possible breadth for rectangle
        vector<int> prev = prevsmallestint(heights, n); //vector for Getting the index of previous smallest integer histogram brakcet to help find the max possible breadth for rectangle
        int area = INT_MIN;

        for (int i = 0; i < n; i++) {
            int l = heights[i]; // length of a rectangle
            if (next[i] == -1) { //if the right of breadth length is -1 change it to n
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1; //max breadth of a possible histogram rectangle
            int newarea = l * b;
            area = max(area, newarea);
        }
        return area;
    }


int main() {    
    vector<int> heights = {2, 1, 5, 6, 2, 3}; // Given heights of reactangle in histogram
    cout << largestRectangleArea(heights) << endl;  // Output should be 10
    return 0;
}
