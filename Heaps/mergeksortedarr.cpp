#include<iostream>
#include<queue>
using namespace std;

//creating a node data structure to store the data, row(kth arr) and col(index val of kth arr).
class node{
    public:
        int data;
        int i;
        int j;

        node(int data,int row,int col){
            this->data=data;
            i=row;
            j=col;
        }
};
class compare{  //to create a min heap(which stores node) such that its sorted based on node-> data
    public:
        bool operator()(node* a,node* b){
            return a->data > b->data;  // bigger ele will come after smaller ele ,i.e smaller ele will be at .top posn
        }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*,vector<node*>,compare> mini;

    //insert 1st ele of all k arrays;  T.C : klog(k)
    for(int i=0;i<k;i++){
        node* temp=new node(kArrays[i][0],i,0);
        mini.push(temp);
    }
    vector<int> ans;
    while(mini.size()>0){
        node* tmp=mini.top();
        ans.push_back(tmp->data); //push the smallest ele at mini in ans(i.e top ele at mini), smallest first ele among k array will get pushed
        mini.pop(); //popping the smallest ele of mini

        // storing the row(kth arr(posn)) and col (index of smallest val of kth array)
        int row=tmp->i;
        int col=tmp->j;

        if(col+1 < kArrays[row].size()){ //pushing the next ele of ktharray(array whose first/next value was smallest) ,in mini(if next ele exist(col+1 < kArrays[row].size())) then that ele will be in its right posn in mini, then smallest ele could be of another array, then taht would get push in ans next and hence we will keep pushing the next ele of the array whose curr ele is smallest at mini 
            node* nxt=new node(kArrays[row][col+1],row,col+1); //pushing next ele with its proper coordinates(i.e array position & index position in that arr)
            mini.push(nxt);
        }

    }
    return ans;
}
//Final T.C : O(n*klog(k))