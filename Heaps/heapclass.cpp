#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }
    //For max heap
    void insert(int data){
        size=size+1;
        int index=size;
        arr[index]=data;  //storing data in array
        while(index>1){  // propogating the node to its correct position
            int parent=index/2;
            if(arr[index]>arr[parent]){
                swap(arr[index],arr[parent]);
                index=parent;
            }
            else{
                return;
            }
        }

    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void deletefromheap(){  // always deleting  root node
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        //put last eolement into last index
        arr[1]=arr[size];

        //delete the last element
        size--;
        int i=1;

        //propogating the new first element to its right place
        while(i<size){
            int leftind=2*i;
            int rightind=(2*i)+1;
            int newind=0;

            //newind= index of the bigger element of its child nodes(taking index of bigger elem so that if arr[i]<childnodes, then to replace it with the bigger child so condition of maxheap fits)
            if(max(arr[leftind],arr[rightind])==arr[leftind]){
                newind=leftind;
            }
            else{
                newind=rightind;
            }
            // checking if max heap condition is inplace , if not then swap according to the right place
            if(arr[i]<arr[newind]){
                swap(arr[i],arr[newind]);
                i=newind;
            }
            else{
                return;
            }
             
        }

    }
};
void maxheapify(int arr[],int n,int i){
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
        maxheapify(arr,n,largest);  //check heap for the node which has been swapped and now is in child position
    }
}

void minheapify(int arr[],int n,int i){  // for zero based array(i.e elements start from 0 posn)
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

void heapsort(int arr[],int n,int i,int size){ // here we are sorting maxheap, we swap the first(biggest) and last(smallest) element such that biggest ele is in last posn of arr and we reduce the size, and then we arrange the new first element to its right position, such that biggest element again comes in top, then we swap first and last again(we are bringing the biggest element in top/first and then sending it to last,each tim reducing the size)
    //base case
    if(size==1){
        return;
    }
    //swapping 1st and last element
    swap(arr[i],arr[size]);

    //reducing size
    size--;

    //arranging first ele in arr/root node in its correct position
    maxheapify(arr,size,1);

    //recursive call
    heapsort(arr,n,i,size);
} //you can also do iteratively using while()

int main(){
    heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);

    h1.print();
    h1.deletefromheap();
    h1.print();

    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        maxheapify(arr,n,i);
    }
    cout<<"printing heaped array"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;

    int che[6]={-1,70,40,50,30,55};
    int n1=5;
    int size=5;
    heapsort(che,n1,1,size);
    cout<<"printing heapsort array"<<endl;
    for(int i=1;i<=n1;i++){
        cout<<che[i]<<" ";
    } 
}