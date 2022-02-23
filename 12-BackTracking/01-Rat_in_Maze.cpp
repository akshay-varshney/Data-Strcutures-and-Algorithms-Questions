// BackTracking: Rat in Maze
//https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/


#include<iostream>
#include<vector>


using namespace std;

bool isSafe(vector<vector<int>> A, int x, int y, int n){
    if(x<n && y<n && A[x][y]==1)
        return true;
    return false;
}

bool ratinMaze(vector<vector<int>> A, int x, int y, int n, vector<vector<int>> &sol){
    if(x==n-1 && y==n-1){
        sol[x][y]=1;
        return true;
    }
    if(isSafe(A, x, y, n)){
        sol[x][y]=1;
        if(ratinMaze(A, x+1, y, n, sol))
            return true;
        if(ratinMaze(A, x, y+1, n, sol))
            return true;
        sol[x][y]=0;
        return false;
    }
    else
        return false;
}



int main()
{

    vector<vector<int>> A={{1, 0, 0, 0},{1, 1, 0, 1},{0, 1, 0, 0},{1, 1, 1, 1}};
    vector<vector<int>> Solution={{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};
    int n=A.size();
    cout<<ratinMaze(A, 0, 0, A.size(), Solution)<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<Solution[i][j]<<" ";
        }
        cout<<endl;
    }
}

