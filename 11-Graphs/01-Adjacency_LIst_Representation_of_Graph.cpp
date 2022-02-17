// Graph: Graph representation using Adjacency List
// https://www.geeksforgeeks.org/graph-and-its-representations/

#include<iostream>
#include<vector>

using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> A[], int start, int end)
{
    A[start].push_back(end);
    A[end].push_back(start);
}


void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v) {
        cout << "\n Adjacency list of vertex " << v
             << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        cout<<endl;
    }
}

int main()
{
    int end = 5;
    vector<int> A[end];
    addEdge(A, 0, 1);
    addEdge(A, 0, 4);
    addEdge(A, 1, 2);
    addEdge(A, 1, 3);
    addEdge(A, 1, 4);
    addEdge(A, 2, 3);
    addEdge(A, 3, 4);
    printGraph(A, end);
    return 0;
}
