
// Dynamic Programming: Longest Repeating Subsequence
//https://www.geeksforgeeks.org/longest-repeating-subsequence/


#include<iostream>
#include<vector>
using namespace std;

// Method 1: By using Recurssion,
int Repeating(string A, int n, int m){
    if(n==0 || m==0)
        return 0;
    if(A[n-1]==A[m-1] && m!=n)
        return 1+Repeating(A, n-1, m-1);
    else
        return max(Repeating(A, n, m-1), Repeating(A, n-1, m));
}
// Time: O(2^n)


// Method 2: By using Memoization
int memoizationRepeating(string A, int n, int m, vector<vector<int>>& dp){
    if(n==0 || m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(A[n-1]==A[m-1] && m!=n)
        return  dp[n][m]= 1+ memoizationRepeating(A, n-1, m-1, dp);
    
    else{
        dp[n][m]= max(memoizationRepeating(A, n-1, m, dp) ,  memoizationRepeating(A, n, m-1, dp) );
        return dp[n][m];
    }
}
// Time: O(n^2)


// Method 3: By using Top Down DP
int topDownRepeating(string A, int n, int m, vector<vector<int>>& dp){
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j==0 || i==0)
                dp[i][j]=0;
            else if(A[i-1]==A[j-1] && i!=j)
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    return dp[n][m];
}


int main(){
    string A= "axxxy";
    int n=A.size();
    cout<<Repeating(A, n, n)<<endl;
    vector<vector<int>> dp(n+1, vector<int> (n+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<memoizationRepeating(A, n, n, dp)<<endl;
    vector<vector<int>> dp2(n+1, vector<int> (n+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=n;j++){
            dp2[i][j]=-1;
        }
    }
    cout<<topDownRepeating(A, n, n, dp2)<<endl;
    dp2.clear();
    dp.clear();
}
