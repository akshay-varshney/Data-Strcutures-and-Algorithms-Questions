// Graphs:Number of Operations to Make Network Connected
//https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include<iostream>
#include<vector>

using namespace std;

 //Definition for a Node.
void dfs(vector<vector<int>>& graph, int i,vector<bool>& visited)
{
    visited[i]=1;
     for(auto it:graph[i]){
         if(!visited[it]) {
             dfs(graph,it,visited);
          }
      }
}
   
 int makeConnected(int n, vector<vector<int>>& connections) {
     if(connections.size()<n-1)
         return -1;
     vector<vector<int>> graph(n);
   
     for(auto &c: connections){
         graph[c[0]].push_back(c[1]);
         graph[c[1]].push_back(c[0]);
     }
   
     int cnt=0;
     vector<bool> visited(n,0);
     for(int i=0;i<n;i++){
         if(!visited[i]){
             dfs(graph,i,visited);
             cnt++;
          }
      }
     return cnt-1;
 }


int main(){
    int n=4;
    vector<vector<int>> connections= {{0,1},{0,2},{1,2}};
    cout<<"Number of Operations to Make Network Connected: "<<makeConnected(n, connections)<<endl;
}
