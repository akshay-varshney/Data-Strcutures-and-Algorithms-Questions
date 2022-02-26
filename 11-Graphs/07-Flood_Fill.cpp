//Graph: Flood Fill
//https://leetcode.com/problems/flood-fill/
/*
 Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
 Output: [[2,2,2],[2,2,0],[2,0,1]]
 */

#include <iostream>
#include<queue>
#include<vector>

using namespace std;

bool isValid(vector<vector<int>>& A, int x1, int x2, int val){
    int n=A.size();
    int m=A[0].size();
    if(x1>=0 && x2>=0 && x1<n && x2<m && A[x1][x2]==val)
        return true;
    return false;
}

// Using BFS 
void floodFill(vector<vector<int>>& A, int src, int sc, int newColor){
    int n=A.size();
    int m=A[0].size();
    queue<std::pair<int, int>> Q1;
    Q1.push({src,sc});
    int val=A[src][sc];
    A[src][sc]+=newColor;
    while(!Q1.empty()){
        auto t=Q1.front();
        Q1.pop();
        if(isValid(A, t.first+1, t.second, val)){
            Q1.push({t.first+1,t.second});
            A[t.first+1][t.second]+=newColor;
        }
        if(isValid(A, t.first-1, t.second, val)){
            Q1.push({t.first-1,t.second});
            A[t.first-1][t.second]+=newColor;
        }
        if(isValid(A, t.first, t.second+1, val)){
            Q1.push({t.first,t.second+1});
            A[t.first][t.second+1]+=newColor;
        }
        if(isValid(A, t.first, t.second-1, val)){
            Q1.push({t.first,t.second-1});
            A[t.first][t.second-1]+=newColor;
        }
    }
}

int main(){
    vector<vector<int>> A= {{0,0,0},{0,0,0},{0,0,0}};
    int src=0;
    int sc=0;
    int newColor=2;
    floodFill(A, src, sc, newColor);
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
