// Dynamic Programming: Matrix Chain Multiplication
//https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

#include<iostream>
#include<vector>
using namespace std;

// Method 1: By using Recurssion,
int matrixMultiplication(vector<int>& A, int i, int j){
    if(i>=j)
        return 0;
    int mini= INT_MAX;
    for(int k=i;k<j; k++){
        int temp= matrixMultiplication(A, i, k)+ matrixMultiplication(A, k+1, j) + A[i-1]*A[k]*A[j];
        mini=min(mini,temp);
    }
    return mini;
}
// Time: O(2^n)



//
// Method 2: By using Memoization
int MemoizationmatrixMultiplication(vector<int>& A, int i, int j, vector<vector<int>>& dp){
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mini= INT_MAX;
    for(int k=i;k<j; k++){
        int temp= MemoizationmatrixMultiplication(A, i, k, dp)+ MemoizationmatrixMultiplication(A, k+1, j, dp) + A[i-1]*A[k]*A[j];
        mini=min(mini,temp);
    }
    return dp[i][j]=mini;
}

int main(){
    vector<int> A={1,2,3,4};
    int n=A.size();
    cout<<matrixMultiplication(A, 1, n-1)<<endl;

    vector<vector<int>> dp(n+1, vector<int> (n+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<MemoizationmatrixMultiplication(A,1,n-1,dp)<<endl;
    dp.clear();
}
