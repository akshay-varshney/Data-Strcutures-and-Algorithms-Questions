// Graph: Prim's Minimum Spanning Tree Algorithm
//https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

#include <iostream>
#include<vector>

using namespace std;

int V;
class Graph {
    vector<pair <int, int> > *edgelist;
public:
    Graph(int V) {
 
        edgelist= new vector<pair<int, int>>(V);
    }
    void addEdge(int x, int y, int w)
    {
        (*edgelist)[x]={y, w };
        (*edgelist)[y]={x, w};
    }
    void primsMst();
};

void Graph::primsMst(){
    vector<int> key(V,INT_MAX);
    vector<bool> mstSet(V,false);
    vector<int> parent(V);
    key[0]=0;
    parent[0]=-1;
    int ans=0;
    for(int i=0;i<V-1; i++){
        int mini=INT_MAX;
        int u;
        for(int j=0;j<V;j++){
            if(mstSet[j]==false && key[j]<mini){
                mini=key[j];
                u=j;
            }
        }
        mstSet[u]=true;
        for(auto iter: edgelist[u]){
            int edge=iter.first;
            int weight= iter.second;
            if(mstSet[edge]==false && weight< key[edge]){
                parent[edge]=u;
                key[edge]=weight;
            }
        }
    }
    for(int i=1; i<V; i++){
        cout<<parent[i]<<"---"<<i<<"---"<<key[i]<<endl;
    }
}
