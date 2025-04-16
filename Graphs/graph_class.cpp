#include<iostream>
#include<unordered_map>
#include<list>
// template <typename T> :to not declare the datatype
using namespace std;

class graph{
    public:
    //creating adjacency list
        unordered_map<int, list<int> > adj;

        void addEdge(int u,int v,bool direction){
            //direction=0->undirected graph
            //direction=1->directed graph

            //create an edge from u to v
            adj[u].push_back(v);

            //checking for undirected graph
            if(direction==false){
                adj[v].push_back(u);
            }
        }
        void printadjlist(){
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<" , ";  
                }
                cout<<endl;
            }
        }
};

int main(){
    int n;
    cout<<"Enter the no of Nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the no of Edge"<<endl;
    cin>>m;
    graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter value of u and v";
        cin>>u>>v;
        //created an undirected graph
        g.addEdge(u,v,0);
    } 

    //printing graph
    g.printadjlist();
}