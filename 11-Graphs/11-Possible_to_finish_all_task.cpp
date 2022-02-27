// Graphs: Find whether it is possible to finish all tasks or not from given dependencies

// https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/

#include<iostream>
#include<vector>

using namespace std;

class Graph
{
    int V=0;
    vector<int> *adj;
public:
    Graph(int v);
    void addEdge(int v, int w);
    bool dfs_cycle(vector<int> *adj, int node, vector<bool>& visited);
    bool canFinish(int numTasks);
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


bool Graph::dfs_cycle(vector<int> *adj, int node,  vector<bool>& visited)
{
    if (visited[node])
        return false;
    visited[node] = true;
    for (int it : adj[node])
        if (visited[it] || dfs_cycle(adj, it, visited))
            return true;
    return visited[node] = false;
}
 

bool Graph::canFinish(int numTasks)
{
    vector<bool> onpath(numTasks, false);
    vector<bool> visited(numTasks, false);
    for (int i = 0; i < numTasks; i++)
        if (!visited[i] && dfs_cycle(adj, i, visited))
            return false;
    return true;
}

//Time: O(V+E)

int main()
{

    Graph g1(4);
    g1.addEdge(1, 0);
    g1.addEdge(2, 1);
    g1.addEdge(3, 2);
    cout<<"This can Finish the Work: "<<g1.canFinish(4)<<endl;
    Graph g(2);
    g.addEdge(1, 0);
    g.addEdge(0, 1);
    cout<<"This can Finish the Work: "<<g.canFinish(2)<<endl;
}
