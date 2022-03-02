// Graph: Kruskal’s Minimum Spanning Tree Algorithm
//https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
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
    void _union(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

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

    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w, x, y });
    }

    void kruskals_mst()
    {
        // 1. Sort all edges
        sort(edgelist.begin(), edgelist.end());

        // Initialize the disjoint
        disjoint s(V);
        int ans = 0;
        cout << "Following are the edges in the "
                "constructed MST"
            << endl;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // take that edge in MST if it does form a cycle
            if (s.find(x) != s.find(y)) {
                s._union(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w
                    << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans<<endl;
    }
};
int main()
{
    /* Let us create following weighted graph
                10
            0--------1
            | \     |
            6| 5\ |15
            |     \ |
            2--------3
                4     */
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
    g.kruskals_mst();
    return 0;
}
