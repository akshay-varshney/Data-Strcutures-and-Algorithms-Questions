//Graph: Euler Graph
//https://www.geeksforgeeks.org/eulerian-path-and-circuit/

#include<iostream>
#include<vector>
#include<queue>

/*
 
 Euler Graph conditions:
1. All the edges must be covered at least once.
 2. Start and end of traversal should be same.
All the vertices must have an even degree.
All the vertices with with non zerso degree are connected
If nodes are not connected it should have degree 0.

 1--2--3
 |     |
 4--5--6
 
 Euler Path: is a path that visits every edge exactly once.
 Semi-Euler Graph conditions:
1. All the edges must be covered at least once.
2. Start != end
Except start and end every vertice will have an even degree. Start and end will have an odd degree.
 
 */

using namespace std;

class Graph {
    int V;

public:
    Graph(int V) { this->V = V; }
    void addEdge(vector<vector<int>> &graph, int u, int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    void DFS(vector<vector<int>>& graph, vector<bool>& visited, int current);
    bool connected(vector<vector<int>>& graph);
    int find_Euler(vector<vector<int>>& graph);
    void print(int val);
};

void Graph::DFS(vector<vector<int> > &graph, vector<bool> &visited, int current){
    visited[current]=true;
    for(auto it:graph[current]){
        if(visited[it]==false)
            DFS(graph, visited, it);
    }
}

int Graph::find_Euler(vector<vector<int> > &graph){
    // check if all the nodes are connected to each other
    if(connected(graph)==false)
        return 0;
    int odd=0;
    // if we find out any edge is not connected then check the degree of unconnected nodes.
    for(int i=0;i<V;i++){
        if(graph[i].size() & 1){
            odd++;
        }
    }
    if(odd>2)
        return 0;
    return (odd==0)?2:1;
}

bool Graph::connected(vector<vector<int> > &graph){
    vector<bool> visited (V, false);
    int node=-1;
    // find the start of the node which have degree greater than 0
    for(int i=0;i<V;i++){
        if(graph[i].size()>0){
            node=i;
            break;
        }
    }
    if(node==-1)
        return true;
    // after finding the node traverse the DFS and we'll left with unconnected nodes and visited value would be false
    DFS(graph, visited, node);
    for(int i=0;i<V;i++){
        // if the node is not visited and degree of the graph is greater than 0 that means it is not a euler graph
        if(visited[i]==false && graph[i].size() >0){
            return false;
        }
    }
    return true;
}

void Graph::print(int val){
    if(val==0)
        cout<<"This Graph is not a Euclid Graph"<<endl;
    else if(val==1)
        cout<<"This Graph is a Semi Euclid Graph"<<endl;
    else
        cout<<"This Graph is Euclid Graph"<<endl;
}


int main()
{
   
    vector<vector<int>> graph (5);
    Graph g(5);
    g.addEdge(graph, 1, 0);
    g.addEdge(graph, 0, 2);
    g.addEdge(graph, 2, 1);
    g.addEdge(graph, 0, 3);
    g.addEdge(graph, 3, 4);
    g.print(g.find_Euler(graph));
    for(int i=0; i<5;i++){
        graph[i].clear();
    }
    
    Graph g1(5);
    g1.addEdge(graph, 1, 0);
    g1.addEdge(graph, 0, 2);
    g1.addEdge(graph, 2, 1);
    g1.addEdge(graph, 0, 3);
    g1.addEdge(graph, 3, 4);
    g1.addEdge(graph, 4, 0);
    g1.print(g1.find_Euler(graph));
    for(int i=0; i<5;i++){
        graph[i].clear();
    }
    Graph g2(5);
    g2.addEdge(graph, 1, 0);
    g2.addEdge(graph, 0, 2);
    g2.addEdge(graph, 2, 1);
    g2.addEdge(graph, 0, 3);
    g2.addEdge(graph, 3, 4);
    g2.addEdge(graph, 1, 3);
    g2.print(g2.find_Euler(graph));
}
