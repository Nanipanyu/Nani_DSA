#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
  return a[2]<b[2];
}

//find parent of a node , initially parent of all node is node itself
int findParent(int node,vector<int> &parent){
  if(parent[node]==node){ //if the node is root node return
    return node;
  }
  //compression technique : set the parent of node in leaf to the root node, instead of the nodes it attached to
  parent[node]=findParent(parent[node],parent);
}

//to make trees(attach trees) using rank:i.e attaching a small tree to a big tree, instead of vice versa
void unionset(int u, int v, vector<int> &parent, vector<int> &rank){
  //Finding the parent of node u and v  
  u=findParent(u,parent); 
  v=findParent(v,parent);

  //Comparing ranks of parent node: i.e which tree is bigger
  if(rank[u]<rank[v]){
    parent[u]=v; //Whose rank is bigger , set parent of smaller rank node(smaller tree) to higher rank node(bigger tree),i.e attaching the smaller tree to the bigger tree
    //here we dont increase the rank because length of tree remains same(a smaller tree has been attached to bigger tree)
  }
  else if(rank[u]>rank[v]){
    parent[v]=u;
  }
  else{
    parent[u]=v;  //if their rank is same(same size trees) attach any tree to any doesnt matter, but increase the rank of root node of tree where u are attaching,because now the length increases
    rank[v]++;
  }

}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<int> parent(n); //storing the parent of nodes(its root node , there can be different components of tree)
  vector<int> rank(n,0);
  for(int i=0;i<n;i++){ ///initially setting parent to itself for each node
    parent[i]=i;
  }
  sort(edges.begin(),edges.end(),cmp); // sort the edges acc to theri weights
  int answt=0; //stroing the cost of weight of spanning tree

  for(int i=0;i<edges.size();i++){ //traversing through the edges
    int u=findParent(edges[i][0],parent); 
    int v=findParent(edges[i][1],parent);
    int wt=edges[i][2];
    if(u!=v){ //if their parent are not same
      unionset(edges[i][0],edges[i][1],parent,rank); //making them a tree and changing their parent
      answt=answt+wt;
    }
  }
  return answt;
}
