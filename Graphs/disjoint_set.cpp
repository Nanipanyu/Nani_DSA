#include<iostream>
#include<vector>
using namespace std;

//In disjoint sets every components has a ultimate node , to keep track of which elements belong to the same group or connected component,

//usecase :
// Network or Connectivity Problems
// Used when you must connect all nodes with minimum operations or edges.
//DSU can count how many connected components exist

//Dynamic Connectivity Problems
// When the graph changes dynamically (edges added/removed), DSU helps maintain component information efficiently
 
//Time complexity of union operation is O(4a) == O(1)   

class DisjointSet{
    vector<int> rank, parent, size;
    public : 
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i; //initially parent of each node is itself
        }
    }

    int findparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findparent(parent[node]); //path compression
    }

    void unionbyrank(int u, int v){
        u=findparent(u);
        v=findparent(v);
        if(u==v) return; //already in same component
        if(rank[u]<rank[v]){                                        //attach the smaller component to bigger component for faster reach
            parent[u]=v;
        }
        else if(rank[v]<rank[u]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }

    void unionbysize(int u, int v){
        u=findparent(u);
        v=findparent(v);
        if(u==v) return; //already in same component
        if(size[u]<size[v]){                             //attach the smaller component to bigger component for faster reach
            parent[u]=v;
            size[v]+=size[u];
        }
        else{
            parent[v]=u;
            size[u]+=size[v];
        }
    }

};

int main(){
    DisjointSet ds(7);
    ds.unionbyrank(1,2);
    ds.unionbyrank(2,3);
    ds.unionbyrank(4,5);
    ds.unionbyrank(6,7);
    ds.unionbyrank(5,6);
    // if we do union of two nodes which are already connected then it will not do anything
    if(ds.findparent(3)==ds.findparent(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    ds.unionbyrank(3,7);
    if(ds.findparent(3)==ds.findparent(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    return 0;
}