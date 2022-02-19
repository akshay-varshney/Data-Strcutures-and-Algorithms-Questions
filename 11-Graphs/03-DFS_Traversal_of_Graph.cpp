// Graphs: DFS Traversal of Graphs
// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/


#include<iostream>
#include<vector>

using namespace std;

class Graph
{
    int V;
    vector<int> *adj;
    vector<int> visited{V};
public:
    Graph(int v);
    void addEdge(int v, int w);
    void DFS(int s);
};

Graph::Graph(int v)
{
    V = v;
    adj = new vector<int>[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int s)
{
    visited[s] = true;
    cout << s << " ";
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (visited[*i]==false)
            {
                visited[*i] = true;
                DFS(*i);
            }
        }
    }

 

int main()
{
    /*
        0
       /  \
       1   2
       | \ |
       3 - 4
        \  /
         5
        */
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    cout << " Depth First Traversal starting from vertex 0: ";
    g.DFS(0);
    cout<<endl;
    return 0;
}

