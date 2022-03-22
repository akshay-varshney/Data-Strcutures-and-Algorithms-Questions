

// Dynamic Programming: Shortest Common Supersequence
//https://www.geeksforgeeks.org/shortest-common-supersequence/


#include<iostream>
#include<vector>
using namespace std;

// Shortest SuperSequence: would be (m+n)-LCS(A,B,m,n)

// Method 1: By using Recurssion,
int LCS(string A, string B, int n, int m){
    if(n==0 || m==0)
        return 0;
    if(A[n-1]==B[m-1])
        return 1+LCS(A, B, n-1, m-1);
    else
        return max(LCS(A, B, n, m-1), LCS(A, B, n-1, m));
}
// Time: O(2^n)


// Method 2: By using Memoization
int memoizationLCS(string A, string B, int n, int m, vector<vector<int>>& dp){
    if(n==0 || m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(A[n-1]==B[m-1])
        return  dp[n][m]= 1+ memoizationLCS(A, B, n-1, m-1, dp);
    
    else{
        dp[n][m]= max(memoizationLCS(A, B, n-1, m, dp) ,  memoizationLCS(A, B, n, m-1, dp) );
        return dp[n][m];
    }
}
// Time: O(n^2)


// Method 3: By using Top Down DP
int topDownLCS(string A, string B, int n, int m, vector<vector<int>>& dp){
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j==0 || i==0)
                dp[i][j]=0;
            else if(A[i-1]==B[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    return ((m+n)-dp[n][m]);
}


int main(){
    string A= "AGGTAB";
    string B= "GXTXAYB";
    int n=A.size();
    int m=B.size();
    cout<<m+n-LCS(A, B, n, m)<<endl;
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    cout<<m+n-memoizationLCS(A, B, n, m, dp)<<endl;
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
