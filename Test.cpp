#include<iostream>
using namespace std;
#include <iostream>
using namespace std;

int findPeak(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < arr[mid + 1]) {
            // Peak is on the right side of mid
            left = mid + 1;
        } else {
            // Peak is on the left side of mid or mid itself is the peak
            right = mid;
        }
    }

    // left or right will point to the peak element
    return arr[left];
}

int main() {
    int arr[8] = {3,3,3,3,3,3,8,6}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    int peak = findPeak(arr, size);
    cout << "The peak value is: " << peak << endl;

    return 0;
}
