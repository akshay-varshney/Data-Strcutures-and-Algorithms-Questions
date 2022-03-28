
// Dynamic Programming:Edit Distance
//https://www.geeksforgeeks.org/edit-distance-dp-5/

#include<iostream>
#include<vector>
using namespace std;

// Method 1: By using Recurssion,
int LCS(string A, string B, int n, int m){
    if(n==0)
        return m;
    if(m==0)
        return n;
    if(A[n-1]==B[m-1])
        return LCS(A, B, n-1, m-1);
    else
        return 1+min(min(LCS(A, B, n, m-1), LCS(A, B, n-1, m)),LCS(A, B, n-1, m-1));
}
// Time: O(2^n)


// Method 2: By using Memoization
int memoizationLCS(string A, string B, int n, int m, vector<vector<int>>& dp){
    if(n==0)
        return dp[n][m]=m;
    if(m==0)
        return dp[n][m]=n;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(A[n-1]==B[m-1])
        return  dp[n][m]=  memoizationLCS(A, B, n-1, m-1, dp);
    
    else{
        dp[n][m]= 1+ min(min(memoizationLCS(A, B, n-1, m, dp) ,  memoizationLCS(A, B, n, m-1, dp)), memoizationLCS(A, B, n-1, m-1, dp));
        return dp[n][m];
    }
}
// Time: O(n^2)


// Method 3: By using Top Down DP
int topDownLCS(string A, string B, int n, int m, vector<vector<int>>& dp){
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j==0 )
                dp[i][j]=i;
            if(i==0)
                dp[i][j]=j;
            else if(A[i-1]==B[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+ min(min(dp[i-1][j] , dp[i][j-1]),dp[i-1][j-1]);
        }
    }
    return dp[n][m];
}


int main(){
    string A= "sunday";
    string B= "saturday";
    int n=A.size();
    int m=B.size();
    cout<<LCS(A, B, n, m)<<endl;
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    cout<<memoizationLCS(A, B, n, m, dp)<<endl;
    vector<vector<int>> dp2(n+1, vector<int> (m+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=m;j++){
            dp2[i][j]=-1;
        }
    }
    cout<<topDownLCS(A, B, n, m, dp2)<<endl;
    dp2.clear();
    dp.clear();
}
