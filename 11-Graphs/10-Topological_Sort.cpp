// Graphs: Topological Sort in a Graph
// For this example, it has been considered that graph is directed and Acyclic.
//The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges)
// https://www.geeksforgeeks.org/topological-sorting/
// If needed then we need to add the code of isCyclic which is discused in: https://github.com/akshay-varshney/Data-Strcutures-and-Algorithms-Questions/blob/main/11-Graphs/04-Check_cycle_in_Directed_Graph.cpp

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Graph
{
    int V=0;
    vector<int> *adj;
public:
    Graph(int v);
    void addEdge(int v, int w);
    bool isCyclic();
    void dfs( vector<int> *adj,int v,vector<bool>& visited, stack<int>& S1);
    vector<int> topologicalSort();
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


void Graph::dfs( vector<int> *adj,int v,vector<bool>& visited,stack<int>& S1)
{
    visited[v] = true;
    for(int i=0;i<adj[v].size();++i){
        if(visited[adj[v][i]]==false)
        {
               dfs(adj,adj[v][i],visited,S1);
        }
    }
    S1.push(v);
}

vector<int> Graph::topologicalSort() {
    vector<int> ans;
   stack<int> S1;
   vector<bool> visited(V,false);

    for(int i=0;i<V;++i){
       if(visited[i]==false)
           dfs(adj,i,visited,S1);
    }
   
   while(!S1.empty())
   {
       ans.push_back(S1.top());
       S1.pop();
   }
   return ans;
}

//Time: O(V+E)

int main()
{

    Graph g1(6);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(4, 0);
    g1.addEdge(4, 1);
    g1.addEdge(5, 0);
    g1.addEdge(5, 2);
    auto V2=g1.topologicalSort();
    cout<<"Topological Sort Order of the given Graph is: ";
    for(auto it=V2.begin(); it!=V2.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
