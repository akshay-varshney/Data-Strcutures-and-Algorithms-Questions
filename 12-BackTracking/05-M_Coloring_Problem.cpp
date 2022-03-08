// BackTracking and Graph: M-Coloring Problem
// https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/

#include<iostream>
#include<vector>


using namespace std;

class Graph {
    int V;

public:
    Graph(int V) { this->V = V; }
    void addEdge(vector<vector<int>> &graph, int u, int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool isSafe(vector<vector<int>>& graph, vector<int>& color, int colorValue, int current);
    bool mColor(vector<vector<int>>& graph, vector<int>& color, int m, int src);
};

// check the current value is safe to place, just check the adjacent vertices
bool Graph::isSafe(vector<vector<int> > &graph, vector<int> &color, int colorValue, int current){
    for(auto i:graph[current]){
        if(color[i]==colorValue)
            return false;
    }
    return true;
}

bool Graph::mColor(vector<vector<int> > &graph, vector<int> &color, int m, int src){
    if(src==V)
        return true;
    
    for(int i=1;i<=m;i++){
        if(isSafe(graph, color, i, src)){
            color[src]=i;
            if(mColor(graph, color, m, src+1)==true)
                return true;
            color[src]=0;
        }
    }
    return false;
}

int main()
{
    int V=5;
    vector<vector<int>> graph (V);
    Graph g(V);
    g.addEdge(graph, 0, 1);
    g.addEdge(graph, 1, 2);
    g.addEdge(graph, 2, 3);
    g.addEdge(graph, 3, 0);
    g.addEdge(graph, 0, 2);
    int m=2;
    vector<int> color(V, 0);
    cout<<g.mColor(graph, color, m, 0)<<endl;
    
}
