#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


bool DFS(vector<vector<int>>& adj, int start, vector<int>& visited, int last)
{
    
    visited[start] = last;
    for(auto it: adj[start])
    {
        if(visited[it] == -1)
        {
            int team = (last == 1? 2:1);
            DFS(adj, it, visited, team);
        }
        else
        {
            if(visited[it] == last)
                return false;
        }
    }
    return true;
}

void createTeams(vector<vector<int>> & A, int n, int size) // 5
{
    vector<vector<int>> adj(n+1);
    for(int i = 0; i<A.size(); i++)
    {
        adj[A[i][0]].push_back(A[i][1]);
        adj[A[i][1]].push_back(A[i][0]);
    }
    vector<int> visited(n+1, -1);
    
    for(int i = 1; i<=n; i++)
    {
        if(visited[i] == -1)
            if(!DFS(adj, i, visited, 1))
            {
                std::cout<<"Impossible"<<std::endl;
                return;
            }
    }
    for(int i = 1; i<visited.size(); i++)
    {
        cout<<visited[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    vector<vector<int>> A = {{1, 2}, {1, 3}, {4, 5}};
    createTeams(A, 5, 3);
}
