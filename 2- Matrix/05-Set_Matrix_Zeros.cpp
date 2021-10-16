// Matrix: Set Matrix Zeros
//https://www.interviewbit.com/problems/set-matrix-zeros/
/*
 Input 1:
     [   [1, 0, 1],
         [1, 1, 1],
         [1, 1, 1]   ]


 Output 1:
     [   [0, 0, 0],
         [1, 0, 1],
         [1, 0, 1]   ]
 */
#include<iostream>
#include<vector>

using namespace std;

void set_zero(vector<vector<int>> &A){
    int n=A.size();
    int m=A[0].size();
    bool Column=false;
    bool Row=false;
    for(int i=0;i<n;i++){
        if(A[i][0]==0) Column=true;
    }
    for(int i=0;i<m;i++){
        if(A[0][i]==0) Row=true;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==0)
            {
                A[i][0]=0;
                A[0][j]=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(A[i][0]==0 || A[0][j]==0){
                A[i][j]=0;
            }
        }
    }
    if(Row){
        for(int i=0;i<m;i++) A[0][i]=0;
    }
    if(Column){
        for(int i=0;i<n;i++) A[i][0]=0;
    }
}


int main(){
    vector<vector<int>> v1={{1,0},{1, 1}};
    set_zero(v1);
    for(auto it=0;it<v1.size();it++){
        for(auto it1=0;it1<v1[0].size();it1++){
            cout<< v1[it][it1] <<" ";
        }
    }
}
