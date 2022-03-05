// Graph: Strongly Connected Components
// https://www.geeksforgeeks.org/strongly-connected-components/

#include <iostream>
#include<vector>
#include<queue>
#include<stack>


// strong connected component: There is a path from one node and return back to the same node
// self loop is also a SCC
/*
 1. Traverse DFS and during the return call store element in stack.
 2. Transpose the graph
 3. Pop elements from stack and do DFS Traversal and each DFS Traversal will give a strong connected component
 */

using namespace std;

class Graph {
    int V;

public:
    Graph(int V) { this->V = V; }
    void addEdge(vector<vector<int>> &graph, int u, int v){
        graph[u].push_back(v);
    }
    void DFS1(vector<vector<int>> &graph, stack<int> &S, int src, vector<bool>& visited);
    void reverseGraph(vector<vector<int>>& graph, vector<vector<int>> & rev);
    void DFS2(vector<vector<int>>& rev, int src, vector<bool>& visited);
    void stronglyConnected(vector<vector<int>> &graph, int src);
};

void Graph::DFS1(vector<vector<int> > &graph, stack<int> &S, int src, vector<bool> &visited){
    visited[src]=true;
    for(auto i:graph[src]){
        if(visited[i]==false)
            DFS1(graph, S, i, visited);
    }
    S.push(src);
}

void Graph::reverseGraph(vector<vector<int> > &graph, vector<vector<int> > &rev){
    for(int i=0;i<V;i++){
        for(int j:graph[i])
            rev[j].push_back(i);
    }
}

void Graph::DFS2(vector<vector<int> > &rev, int src, vector<bool> &visited){
    cout<<src<<" ";
    visited[src]=true;
    for(int j:rev[src]){
        if(visited[j]==false)
            DFS2(rev, j, visited);
    }
}


void Graph::stronglyConnected(vector<vector<int> > &graph, int src){
    stack<int> S;
    vector<bool> visited(V, false);
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            DFS1(graph, S, i, visited);
    }
    vector<vector<int>> rev(V);
    reverseGraph(graph, rev);
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    int count=0;
    cout<<"All Strongly connected components: "<<endl;
    while(!S.empty()){
        int current=S.top();
        S.pop();
        if(visited[current]==false){
            DFS2(rev, current, visited);
            cout<<endl;
            count++;
        }
       
    }
    cout<<"Total Strongly Connected Components of Graph are: "<<count<<endl;
}
// Time: O(V+E)


int main()
{
   
    vector<vector<int>> graph (8);
    Graph g(8);
    g.addEdge(graph, 0, 1);
    g.addEdge(graph, 1, 2);
    g.addEdge(graph, 2, 0);
    g.addEdge(graph, 2, 3);
    g.addEdge(graph, 3, 4);
    g.addEdge(graph, 4, 5);
    g.addEdge(graph, 4, 7);
    g.addEdge(graph, 5, 6);
    g.addEdge(graph, 6, 4);
    g.addEdge(graph, 6, 7);
    g.stronglyConnected(graph, 0);
    return 0;
}
