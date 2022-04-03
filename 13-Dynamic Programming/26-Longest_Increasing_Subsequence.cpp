// Dynamic Programming: Longest Increasing Subsequence
//https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

// Method 1: By using another vector and storing the previous count of longest increasing Subsequence
int longestIncreasingSubse(vector<int>& A){
    int n=A.size();
    vector<int> SubsequenceVal(n,1);
    for(int i=1; i<n; i++){
        for(int j=0;j<i;j++){
            if(A[i]> A[j] && SubsequenceVal[i]<=SubsequenceVal[j])
                SubsequenceVal[i]= SubsequenceVal[j]+1;
        }
    }
    int maxi= SubsequenceVal[0];
    for(int i=1;i<n;i++){
        maxi=max(maxi, SubsequenceVal[i]);
    }
    return maxi;
}
// Time: O(n^2) and Space: O(n)

// Method 2: by using Dynamic Programming
// If we sort the vector and having non duplicate number then we can apply LCS to get the longest increasing Subsequence.

// Method  2(a): By using Recurssion,
int LCS(vector<int>& A, vector<int>& B, int n, int m){
    if(n==0 || m==0)
        return 0;
    if(A[n-1]==B[m-1])
        return 1+LCS(A, B, n-1, m-1);
    else
        return max(LCS(A, B, n, m-1), LCS(A, B, n-1, m));
}
// Time: O(2^n)


// Method 2(b): By using Memoization
int memoizationLCS(vector<int>& A, vector<int>& B, int n, int m, vector<vector<int>>& dp){
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


// Method 2(c): By using Top Down DP
int topDownLCS(vector<int>& A, vector<int>& B, int n, int m, vector<vector<int>>& dp){
    
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
    return dp[n][m];
}



int main(){
    vector<int> A= {10, 22, 9, 33, 21, 50, 41, 60};
    cout<<"Longest Increasing Subsequence by using nomral method is: "<<longestIncreasingSubse(A)<<endl;
    set<int> S;
    int n=A.size();
    for(int i=0;i<n; i++){
        S.insert(A[i]);
    }
    vector<int> B;
    for(auto it:S){
        B.push_back(it);
    }
    
    int m=B.size();
    cout<<"Longest Increasing Subsequence by using Recursion is: "<<LCS(A, B, n, m)<<endl;
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    cout<<"Longest Increasing Subsequence by using Memoization method is: "<<memoizationLCS(A, B, n, m, dp)<<endl;
    vector<vector<int>> dp2(n+1, vector<int> (m+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=m;j++){
            dp2[i][j]=-1;
        }
    }
    cout<<"Longest Increasing Subsequence by using Top Down method is: "<<topDownLCS(A, B, n, m, dp2)<<endl;
    dp2.clear();
    dp.clear();
}

