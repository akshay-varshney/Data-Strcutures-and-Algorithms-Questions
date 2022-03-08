// BackTracking: Sodoku Solver
//https://www.geeksforgeeks.org/sudoku-backtracking-7/

#include<iostream>
#include<vector>

using namespace std;

// Check if the current placement is valid or not
bool isvalid(vector<vector<int>>& board, int row, int col, int data){
    for(int i=0;i<9;i++){
        if(board[i][col]==data)
            return false;
        if(board[row][i]==data)
            return false;
        if(board[3 * (row/3) +(i/3)][3* (col/3) + (i%3)]==data)
            return false;
    }
    return true;
}

bool sodoku(vector<vector<int>>& board){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j]==0){
                for(int k=1;k<=9;k++){
                    // if the current placement comes to be valid then just add the current value to the board otherwise set value to 0 and backTrack
                    if(isvalid(board, i, j, k)){
                        board[i][j]=k;
                        
                        if(sodoku(board)==true)
                            return true;
                        else
                            board[i][j]=0;
                        
                    }
                }
                return false;
            }
        }
    }
    return true;
}


int main(){
    vector<vector<int>> A={ { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
        { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
        { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
        { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
        { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
        { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
        { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    
    sodoku(A);
    cout<<"Solved Sodoku is: "<<endl;
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[0].size(); j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
