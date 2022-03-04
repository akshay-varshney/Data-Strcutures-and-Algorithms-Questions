// Graph: Dijkstra's Shortest Path Algorithm
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

#include <iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph {
    vector<vector<int> > edgelist;
    int V;

public:
    Graph(int V) { this->V = V; }
    void addEdge(vector<pair<int, int>> graph[], int u, int v, int w){
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    void shortestPath(vector<pair<int, int>> graph[], int src);
};

void Graph::shortestPath(vector<pair<int, int>> graph[], int src){
    // use priority queue as min heap
      priority_queue<pair<int, int>> pq;
      // distance vector to check the distance traversed till now
      vector<int>dist(V, INT_MAX);
      pq.push(make_pair(0, src)); // pushing the source with 0 distance
      dist[src] = 0;
      // normal BFS traversal
      while(!pq.empty()){
          int u = pq.top().second;
          pq.pop();
          // traverse for the neighbors of u
          for(auto x : graph[u]){
              // x = {v, wt}
              int v = x.first;
              int wt = x.second;
              if(dist[v]>dist[u] + wt){
                  dist[v] = dist[u] + wt;
                  pq.push(make_pair(dist[v], v));
              }
          }
      }
      cout<<"Vertex   Distance from src\n";
      for(int i=0; i<V; i++)
          cout<<i<<"\t\t\t"<<dist[i]<<endl;
  }

// Time: O(ElogV)


int main()
{
    Graph g1(9);
    vector<pair<int, int>> graph[9];
    g1.addEdge(graph ,0, 1, 4);
    g1.addEdge(graph ,0, 7, 8);
    g1.addEdge(graph ,1, 2, 8);
    g1.addEdge(graph ,1, 7, 11);
    g1.addEdge(graph ,2, 3, 7);
    g1.addEdge(graph ,2, 8, 2);
    g1.addEdge(graph ,2, 5, 4);
    g1.addEdge(graph ,3, 4, 9);
    g1.addEdge(graph ,3, 5, 14);
    g1.addEdge(graph ,4, 5, 10);
    g1.addEdge(graph ,5, 6, 2);
    g1.addEdge(graph ,6, 7, 1);
    g1.addEdge(graph ,6, 8, 6);
    g1.addEdge(graph ,7, 8, 7);
    g1.shortestPath(graph, 0);
    return 0;
}
