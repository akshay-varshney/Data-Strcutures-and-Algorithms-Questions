// Graph: Check cycle in undirected Graph using Disjoint Set

#include <iostream>
#include<vector>

using namespace std;


class disjoint {
    vector<int> *parent;
    vector<int> *rank;

public:
    disjoint(int n)
    {
        parent = new vector<int>(n);
        rank = new vector<int>(n);

        for (int i = 0; i < n; i++) {
            (*parent)[i] = -1;
            (*rank)[i] = 1;
        }
    }

    // Find function
    int find(int i)
    {
        if ((*parent)[i] == -1)
            return i;

        return (*parent)[i] = find((*parent)[i]);
    }
    // union function
    void _union(int s1, int s2)
    {
//        int s1 = find(x);
//        int s2 = find(y);

        if (s1 != s2) {
            if ((*rank)[s1] < (*rank)[s2]) {
                (*parent)[s1] = s2;
            }
            else if ((*rank)[s1] > (*rank)[s2]) {
                (*parent)[s2] = s1;
            }
            //Both have same rank and so anyone can be made as parent
            else {
                (*parent)[s2] = s1;
                (*rank)[s1]++;
                //Increase rank of parent
            }
        }
    }
};

class Graph {
    vector<vector<int> > edgelist;
    int V;

public:
    Graph(int V) { this->V = V; }
    bool isCyclic();
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w, x, y });
    }
};

bool Graph::isCyclic(){
    disjoint s(V);
    
    for (auto edge : edgelist) {
        int x = s.find(edge[1]);
        int y = s.find(edge[2]);
        if(x==y)
            return true;
    
        s._union(x, y);
        }
    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    cout<<"The given graph is cycic: "<<g.isCyclic()<<endl;
    Graph g1(4);
    g1.addEdge(0, 1, 10);
    g1.addEdge(1, 3, 15);
    g1.addEdge(2, 3, 4);
    g1.addEdge(2, 0, 6);
    g1.addEdge(0, 3, 5);
    cout<<"The given graph is cycic: "<<g1.isCyclic()<<endl;
    return 0;
}
