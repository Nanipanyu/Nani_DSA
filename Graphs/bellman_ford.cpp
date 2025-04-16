#include<iostream>
#include<vector>
using namespace std;

//BEllman-Fords is an algo to find shortest distance from arc node in Graph with negative weights present, it can also be used to check presence of negative cycles 

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    
    vector<int> distance(n+1,100000000); //Instant of INT_MAX using 1000000
    distance[src]=0; //distance of src with itself 0
    for(int j=0;j<n-1;j++){ //traverse through all edges n-1 times so that all possible shortest path is checked
        bool updated=false; //for early stopage if shortest path is found mid traversal , that is distance has stopped updating
        for(int i=0;i<m;i++){ //traverse through all edges pair
            if(distance[edges[i][0]]!=100000000 && distance[edges[i][1]]>distance[edges[i][0]]+edges[i][2]){ //what if first node(in edge pair) is not src than in  distance[edges[i][1]]>distance[edges[i][0]]+edges[i][2], RHS overflows, so edges[i][0]]!=100000000 is checked 
                distance[edges[i][1]]=distance[edges[i][0]]+edges[i][2];
                updated=true; //paths are being updated, shorter paths are found
            }
            
        }
        if(!updated) break;
    }
    bool negcyclepresent=false;
    for(int i=0;i<m;i++){ //traverse through all edges pair
        if(distance[edges[i][0]]!=100000000 && distance[edges[i][1]]>distance[edges[i][0]]+edges[i][2]){ //what if first node(in edge pair) is not src than in  distance[edges[i][1]]>distance[edges[i][0]]+edges[i][2], RHS overflows, so edges[i][0]]!=100000000 is checked 
            distance[edges[i][1]]=distance[edges[i][0]]+edges[i][2];
            negcyclepresent=true; //paths are still being updated, means there is an self loop with negative weights, i.e negative cycle
        }
        
    }
    if(negcyclepresent) {
        cout<<" SHortest distance can never be found";
    }

     return  distance;

}