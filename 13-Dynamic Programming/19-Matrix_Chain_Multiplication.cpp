
// Dynamic Programming: Matrix Chain Multiplication
//https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

#include<iostream>
#include<vector>
using namespace std;

// Method 1: By using Recurssion,
int matrixMultiplication(vector<int>& A, int i, int j){
    cout<<"i"<<i<<j<<endl;
    if(i>=j)
        return 0;
    int mini= INT_MAX;
    for(int k=i;k<j; k++){
        cout<<"k"<<k<<i<<j<<endl;
        int temp= matrixMultiplication(A, i, k)+ matrixMultiplication(A, k+1, j) + A[i-1]*A[k]*A[j];
        mini=min(mini,temp);
        cout<<"M"<<mini<<endl;
    }
    return mini;
}


// Time: O(2^n)

//
//// Method 2: By using Memoization
//int memoizationLCS(string A, string B, int n, int m, vector<vector<int>>& dp){
//    if(n==0 || m==0)
//        return 0;
//    if(dp[n][m]!=-1)
//        return dp[n][m];
//    if(A[n-1]==B[m-1])
//        return  dp[n][m]= 1+ memoizationLCS(A, B, n-1, m-1, dp);
//
//    else{
//        dp[n][m]= max(memoizationLCS(A, B, n-1, m, dp) ,  memoizationLCS(A, B, n, m-1, dp) );
//        return dp[n][m];
//    }
//}
//// Time: O(n^2)
//
//
//// Method 3: By using Top Down DP
//int topDownLCS(string A, string B, int n, int m, vector<vector<int>>& dp){
//
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=m;j++){
//            if(j==0 || i==0)
//                dp[i][j]=0;
//            else if(A[i-1]==B[j-1])
//                dp[i][j]=1+dp[i-1][j-1];
//            else
//                dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
//        }
//    }
//    return dp[n][m];
//}


int main(){
    vector<int> A={1,2,3,4,3};
    int n=A.size();
    cout<<matrixMultiplication(A, 1, n-1)<<endl;
//    int n=A.size();
//    int m=B.size();
//    cout<<"Total Number of Insertions by recurssion solution: "<<n-LCS(A, B, n, m)<<endl;
//    vector<vector<int>> dp(n+1, vector<int> (m+1));
//    for(int i=0; i<=n; i++){
//        for(int j=0;j<=m;j++){
//            dp[i][j]=-1;
//        }
//    }
//    cout<<"Total Number of Insertions by memoization: "<<n-memoizationLCS(A, B, n, m, dp)<<endl;
//    vector<vector<int>> dp2(n+1, vector<int> (m+1));
//    for(int i=0; i<=n; i++){
//        for(int j=0;j<=m;j++){
//            dp2[i][j]=-1;
//        }
//    }
//    cout<<"Total Number of Insertions by TopDown: "<<n-topDownLCS(A, B, n, m, dp2)<<endl;
//    dp2.clear();
//    dp.clear();
}


