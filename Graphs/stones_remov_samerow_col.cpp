#include<iostream>
#include<vector>
#include<set>
using namespace std;

//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
//On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
//A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
//Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

//Basically this is a graph problem of disjoint set union, where each row/col is a node and each stone is an edge between the row node and col node
//So we have to find the number of connected components in the graph, and the answer will be total stones - number of connected components
//because in each connected component we can remove all stones except one, stones with same row or col are connected

class Solution {
public:
    class DisjointSet{
        vector<int> parent, rank;
        public:
        DisjointSet(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        int findparent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node]=findparent(parent[node]);
        }
        void unionbyrank(int u , int v){
            u=findparent(u);
            v=findparent(v);
            if(u==v) return;
            if(rank[u]>rank[v]){
                parent[v]=u;
            }
            else if(rank[v]>rank[u]){
                parent[u]=v;
            }
            else{
                parent[u]=v;
                rank[v]++;
            }
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0 , maxcol = 0;

        for(int i = 0;i<stones.size();i++){
            maxrow = max(maxrow,stones[i][0]);                     // find max row
            maxcol = max(maxcol,stones[i][1]);                     // find max col
        }
        DisjointSet ds(maxrow+maxcol+2);                           // create disjoint set of size maxrow+maxcol+2 ( +2 for 0 based indexing and extra space)
        set<int> insertednode;
        int offset = maxrow + 1;                                   // offset to differentiate between row and col nodes in disjoint set, col nodes will start from maxrow+1
        for(auto &s : stones){
            int row = s[0];
            int col = s[1]+offset;                                 // col node will be col index + offset
            ds.unionbyrank(row,col);                               // union the row and col nodes
            insertednode.insert(row);                              // insert the row node in set to count unique nodes later
            insertednode.insert(col);
        }
        int components = 0;
        for (auto j : insertednode) {
            if (j == ds.findparent(j)) {                            // if the node is its own parent, it is a root node of a component, so we count it as a component
                components++;
            }
        }
        return stones.size() - components;
    }
};