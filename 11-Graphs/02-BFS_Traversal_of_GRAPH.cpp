// Graphs: BFS Traversal of Graph
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph
{
    int V;
    vector<int> *adj;
public:
    Graph(int v);
    void addEdge(int v, int w);
    void BFS(int s);
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

void Graph::BFS(int s)
{
    vector<int> visited{V};
    for(int i = 0; i < V; i++)
        visited[i] = false;
    queue<int> Q;
    visited[s] = true;
    Q.push(s);
    while(!Q.empty())
    {
        s = Q.front();
        cout << s << " ";
        Q.pop();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (visited[*i]==false)
            {
                visited[*i] = true;
                Q.push(*i);
            }
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
    cout << " Breadth First Traversal starting from vertex 0): ";
    g.BFS(0);
    cout<<endl;
    return 0;
}

