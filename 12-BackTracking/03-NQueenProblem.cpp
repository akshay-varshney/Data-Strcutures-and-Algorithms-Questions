// BackTracking: NQueen Probelm
// Find Positions in chess board where all nQueens can be placed

#include<iostream>
#include<vector>

using namespace std;


bool isSafe(vector<vector<int>> &A, int x, int y, int n){
    // check the row wise
    for(int r=0; r<x; r++){
        if(A[r][y]==1)
            return false;
    }
    int r=x;
    int c=y;
    // Left Diagonal
    while(r>=0 && c>=0){
        if(A[r][c]==1)
            return false;
        r--;
        c--;
    }
    r=x;
    c=y;
    // right diagonal
    while(r>=0 && c>=0){
        if(A[r][c]==1)
            return false;
        r--;
        c++;
    }
    return true;
}

bool nQueen(vector<vector<int>>& A, int x, int n){
    if(x>=n)
        return true;
    for(int i=0;i<n;i++){
        if(isSafe(A, x, i, n)){
            A[x][i]=1;
            if(nQueen(A, x+1, n))
                return true;
            A[x][i]=0; // bacTrack to last position
        }
    }
    return false;
}

 

int main() {
//    int n = 4;
    vector<vector<int>> A = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int n=A.size();
    if(nQueen(A, 0, A.size())){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
    }
    }
    return 0;
}
