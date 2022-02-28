// Graphs: Find the number of islands
// https://leetcode.com/problems/number-of-islands/

#include<iostream>
#include<vector>

using namespace std;


void mark_current_island(vector<vector<int>> &A,int x,int y,int r,int c)
{
   if(x<0 || x>=r || y<0 || y>=c || A[x][y]!=1)
       return;
    
   A[x][y] = 2;
   mark_current_island(A,x+1,y,r,c);  //DOWN
   mark_current_island(A,x,y+1,r,c);  //RIGHT
   mark_current_island(A,x-1,y,r,c);  //TOP
   mark_current_island(A,x,y-1,r,c);  //LEFT
}

int numIslands(vector<vector<int>>& A) {

   int rows = A.size();
   int cols = A[0].size();
   int count = 0;
   for(int i=0;i<rows;++i)
   {
       for(int j=0;j<cols;++j)
       {
           if(A[i][j]==1)
           {
               mark_current_island(A,i,j,rows,cols);
               count += 1;
           }
       }
   }
   return count;
}

// Time: O(n*m)
// Space: O(n*m)

int main()
{
    vector<vector<int>> A={{1,1,0,0,0},{0,1,0,0,1},{1,0,0,1,1},{0,0,0,0,0},{1,0,1,0,1}};
    cout<<numIslands(A)<<endl;
}
