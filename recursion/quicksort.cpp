#include<iostream>
using namespace std;
int partition(int *arr,int s,int e){
    int pivot=arr[s];
    int count=0;
    for(int i=s;i<=e;i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    int position=s+count;
    swap(arr[s],arr[position]);
    int i=s,j=e;
    while(i<position && j>position){
       
            if(arr[i]>arr[position] && arr[j]<arr[position]){
                swap(arr[i++],arr[j--]);
            }
            else if(arr[i]<arr[position] && arr[j]>=arr[position]){
                i++;               
            }
            else if(arr[i]>=arr[position] && arr[j]>arr[position]){
                j--;
            }
            else if(arr[i]<arr[position] && arr[j]<arr[position]){
                i++;
            }
            // if(i==position && j==position){
            //     break;
            // }   
    } 
    return position;
}
void quicksort(int *arr,int s,int e){
    
    if(s>=e){
        return;
    }
    // creating partition
    int p=partition(arr,s,e);
    // left array
    quicksort(arr,s,p-1);
    // right array
    quicksort(arr,p+1,e);
}

int main(){
    int num[9]={3,5,1,8,2,4,0,6,1};
    int bum[5]={8,6,2,1,9};
    quicksort(num,0,8);
    quicksort(bum,0,4);
    for(auto i:num){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:bum){
        cout<<i<<" ";
    }
}