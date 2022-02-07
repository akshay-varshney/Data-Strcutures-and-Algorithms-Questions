// Matrix: Rotate Matrix 90 degree cloclwise
//https://www.interviewbit.com/problems/rotate-matrix/
/*
 Input 1:
     [   [1, 2, 3],
         [4, 5, 6],
         [7, 8, 9]   ]


 Output 1:
     [   [7, 4, 1],
         [8, 5, 2],
         [9, 6, 3]   ]
 */
#include<iostream>
#include<vector>

using namespace std;

void Rotate_Matrix(vector<vector<int>> &A){
    int n=A.size();
    int m=A[0].size();
    // Taking the transpose of the matrix
    for(int i=0;i<n;i++){
        for(int j=i;j<m;j++){
            swap(A[i][j], A[j][i]);
        }
    }
    // Reversing element row wise
    for(int i=0;i<n;i++){
        int start=0;
        int end=m-1;
        while(start<=end){
            swap(A[i][start],A[i][end]);
            start++;
            end--;
        }
    }
}
// Time: O(m*n) and Space: O(1)


int main(){
    vector<vector<int>> v1={{1,2},{3,4}};
    Rotate_Matrix(v1);
    for(auto it=0;it<v1.size();it++){
        for(auto it1=0;it1<v1[0].size();it1++){
            cout<< v1[it][it1] <<" ";
        }
    }
}
