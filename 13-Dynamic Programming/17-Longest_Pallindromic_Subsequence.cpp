
// Dynamic Programming: Longest Pallindrome Subsequence
//https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

/*
 Here we are given only one string but for LCS pattern question we need two strings, so we'll generate B string by reversing A string.
 */

#include<iostream>
#include<vector>
using namespace std;

// Method 1: By using Memoization
int memoizationLPS(string A, string B, int n, int m, vector<vector<int>>& dp){
    if(n==0 || m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(A[n-1]==B[m-1])
        return  dp[n][m]= 1+ memoizationLPS(A, B, n-1, m-1, dp);
    
    else{
        dp[n][m]= max(memoizationLPS(A, B, n-1, m, dp) ,  memoizationLPS(A, B, n, m-1, dp) );
        return dp[n][m];
    }
}
// Time: O(n^2)


// Method 2: By using Top Down DP
void topDownLPS(string A, string B, int n, int m, vector<vector<int>>& dp){
    
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
}

void printLPS(string A, string B, vector<vector<int>>& dp){
    int i=A.size();
    int j=B.size();
    string ans="";
    while(i>0 && j>0){
        if(A[i-1]==B[j-1]){
            ans+=A[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]> dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    for(int i=ans.size(); i>=0; i--){
        cout<<ans[i];
    }
    cout<<endl;
}


int main(){
    string A= "GEEKSFORGEEKS";
    string B= A;
    reverse(B.begin(), B.end());
    int n=A.size();
    int m=B.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    memoizationLPS(A, B, n, m, dp);
    printLPS(A, B, dp);
    vector<vector<int>> dp2(n+1, vector<int> (m+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=m;j++){
            dp2[i][j]=-1;
        }
    }
    topDownLPS(A, B, n, m, dp2);
    printLPS(A, B, dp2);
    dp2.clear();
    dp.clear();
}
