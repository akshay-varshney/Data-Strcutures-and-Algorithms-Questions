// Matrix: Spirally traversing a matrix
// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
/*
 matrix[][] = {{1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15,16}}
 Output:
 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
 */
#include<iostream>
#include<vector>

using namespace std;
// in this problem we take 4 pointers denoting the direction of the traversal as top, left, right and down. Our Direction of movement in the spiral matrix is from left to right, top to down, right to left, down to top.

// We take another direction pointer which will denote the direction. 
void spiral_matrix(vector<vector<int>> &A){
    int r=A.size();
    int c=A[0].size();
    int top=0;
    int left=0;
    int right=r-1;
    int down=c-1;
    int direction=0;
    while(top<=down && left<=right){
        if(direction==0){
            for(int i=left;i<=right;i++){
                cout<<A[top][i]<<" ";
            }
            top++;
        }
        else if(direction==1){
            for(int i=top;i<=down;i++){
                cout<<A[i][right]<<" ";
            }
            right--;
        }
        else if(direction==2){
            for(int i=right;i>=left;i--){
                cout<<A[down][i]<<" ";
            }
            down--;
        }
        else if(direction==3){
            for(int i=down;i>=top;i--){
                cout<<A[i][left]<<" ";
            }
            left++;
        }
        direction=(direction+1)%r;
    }
    cout<<endl;
}


int main(){
    vector<vector<int>> v1={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    spiral_matrix(v1);
}
