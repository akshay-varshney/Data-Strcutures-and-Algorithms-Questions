// Dynamic Programming: Print Longest common subsequence
//https://www.geeksforgeeks.org/printing-longest-common-subsequence/


#include<iostream>
#include<vector>
using namespace std;

// Method 1: By using Memoization
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


// Method 2: By using Top Down DP
void topDownLCS(string A, string B, int n, int m, vector<vector<int>>& dp){
    
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

void printLCS(string A, string B, vector<vector<int>>& dp){
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
    string A= "AGGTAB";
    string B= "GXTXAYB";
    int n=A.size();
    int m=B.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    memoizationLCS(A, B, n, m, dp);
    printLCS(A, B, dp);
    vector<vector<int>> dp2(n+1, vector<int> (m+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=m;j++){
            dp2[i][j]=-1;
        }
    }
    topDownLCS(A, B, n, m, dp2);
    printLCS(A, B, dp2);
    dp2.clear();
    dp.clear();
}
