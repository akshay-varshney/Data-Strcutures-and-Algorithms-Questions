// BackTracking: Rat in a Maze Problem - I
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
#include<iostream>
#include<vector>
/*
 m[][] = {{1, 0, 0, 0},
          {1, 1, 0, 1},
          {1, 1, 0, 0},
          {0, 1, 1, 1}}
 Output:
 DDRDRR DRDDRR
 */

using namespace std;

// backtrack to the last succesfull path
void ratInMaze(int i, int j, vector<vector<int>> & A, int n, vector<string> & ans, string move, vector<vector<int>> & vis) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }

    // downward direction
    if (i + 1 < n && vis[i + 1][j]==0 && A[i + 1][j] == 1) {
      vis[i][j] = 1;
      ratInMaze(i + 1, j, A, n, ans, move + 'D', vis);
      vis[i][j] = 0;
    }

    // left direction
    if (j - 1 >= 0 && vis[i][j - 1]==0 && A[i][j - 1] == 1) {
      vis[i][j] = 1;
      ratInMaze(i, j - 1, A, n, ans, move + 'L', vis);
      vis[i][j] = 0;
    }

    // right direction
    if (j + 1 < n && vis[i][j + 1]==0 && A[i][j + 1] == 1) {
      vis[i][j] = 1;
      ratInMaze(i, j + 1, A, n, ans, move + 'R', vis);
      vis[i][j] = 0;
    }

    // upward direction
    if (i - 1 >= 0 && vis[i - 1][j]==0 && A[i - 1][j] == 1) {
      vis[i][j] = 1;
      ratInMaze(i - 1, j, A, n, ans, move + 'U', vis);
      vis[i][j] = 0;
    }
}
     
vector <string> validPath(vector <vector<int>> & A, int n) {
  vector<string> ans;
  vector<vector<int>> vis(n, vector<int> (n, 0));
  if (A[0][0] == 1)
      ratInMaze(0, 0, A, n, ans, "", vis);
  return ans;
}


int main() {
    int n = 4;
    vector<vector<int>> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> result = validPath(m, n);
    if (result.size() == 0)
        cout << -1;
    else
    {
        for (int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
