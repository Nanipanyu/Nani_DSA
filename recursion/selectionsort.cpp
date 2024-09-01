#include<iostream>
#include<algorithm>
using namespace std;
void select(int *arr,int n){
    if(n==1){
        return;
    }
    int start=0;
    int minindex=start;
    for(int i=start+1;i<n;i++){
        if(arr[minindex]>arr[i]){
            minindex=i;       
            }
    }
    swap(arr[minindex],arr[start]);
    
    select(arr+1,n-1);
    
}
int main(){
    int num[5]={};
    cout<<"Enter your array values"<<" ";
    for(int i=0;i<5;i++){
        cin>>num[i];
    }
    select(num,5);
    for(auto i:num){
        cout<<i<<" ";

    }
}
// #include <iostream>

// void swap(int &a, int &b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// void selectionSort(int arr[], int size, int start = 0) {
//     if (start == size - 1) {
//         return; // Base case: If we've reached the end of the array, stop.
//     }

//     int minIndex = start;
//     for (int i = start + 1; i < size; i++) {
//         if (arr[i] < arr[minIndex]) {
//             minIndex = i;
//         }
//     }

//     if (minIndex != start) {
//         swap(arr[start], arr[minIndex]);
//     }

//     // Recursively sort the rest of the array
//     selectionSort(arr, size, start + 1);
// }

// int main() {
//     int arr[] = {64, 25, 12, 22, 11};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     selectionSort(arr, size);

//     std::cout << "Sorted array is: ";
//     for (int i = 0; i < size; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }

