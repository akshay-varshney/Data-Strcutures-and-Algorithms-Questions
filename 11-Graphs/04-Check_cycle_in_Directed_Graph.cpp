// Graphs: Check Cycle in a Directed Graph
// https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

#include<iostream>
#include<vector>

using namespace std;

class Graph
{
    int V;
    vector<int> *adj;
    vector<int> visited{V, false};
public:
    Graph(int v);
    void addEdge(int v, int w);
    bool iscyclic();
    bool checkCycle(vector<int> visited, int current);
};

Graph::Graph(int v)
{
    V = v;
    adj = new vector<int>[V];
   
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::checkCycle(vector<int> visited, int current)
{
    if(visited[current]==true)
        return true;
    visited[current]= true;
    bool flag= false;
    for(int i=0;i< adj[current].size(); i++){
        flag=checkCycle(visited, adj[current][i]);
        if(flag==true)
            return true;
    }
    return false;
}

bool Graph::iscyclic(){
    bool flag=false;
    // Traversing each vertices
    for(int i=0; i<V;i++){
        visited[i]= true;
        // trversing each node which is connected through a particular vertice
        for(int j=0;j< adj[i].size(); j++){
            flag= checkCycle(visited, adj[i][j]);
            if(flag)
                return true;
        }
        visited[i]= false;
        // once traversal done make the current edge back to false
    }
    return false;
}

int main()
{
    /*
     
     1-->2--
     ^  ^ | |
     |  | 3 |
     0<-----
     
    0-> 1,2
    1->2
    2-> 0, 3
    3->3
     
        */
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "The given graph contains cycle: ";
    cout<<g.iscyclic()<<endl;
    return 0;
}

