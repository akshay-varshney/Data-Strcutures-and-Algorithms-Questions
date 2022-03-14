// Dynamic Programming: Equal Partition
// https://www.geeksforgeeks.org/partition-problem-dp-18/


#include<iostream>
#include<vector>
using namespace std;

// Method 1: By using Recurssion
bool sumSubset(vector<int>& A, int n, int Sum){
    if(Sum==0)
        return true;
    if(n==0 && Sum!=0)
        return false;
    if(A[n-1]>Sum)
        return sumSubset(A, n-1, Sum);
    else
        return (sumSubset(A, n-1, Sum) || sumSubset(A, n-1, Sum-A[n-1]));
}

// Method 2: By using Memoization
bool memoizationSubset(vector<int>& A, int n, int Sum, vector<vector<int>>& dp){
    if(Sum==0)
        return true;
    if(n<=0)
        return false;
    if(dp[n-1][Sum]!=-1)
        return dp[n-1][Sum];
    if(A[n-1]>Sum){
        dp[n-1][Sum]= memoizationSubset(A, n-1, Sum, dp);
        return dp[n-1][Sum];
    }
    else{
        dp[n-1][Sum]= (memoizationSubset(A, n-1, Sum, dp) || memoizationSubset(A, n-1, Sum- A[n-1], dp));
        return dp[n-1][Sum];
    }
}

// Method 3: By using Top Down DP
bool topDownSubset(vector<int>& A, int n, int Sum, vector<vector<int>>& dp){
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=Sum;j++){
            if(j==0 && i==0)
                dp[i][j]=true;
            else if(i==0 && j!=0)
                dp[i][j]=false;
            else if(j==0 && i!=0)
                dp[i][j]=true;
            else if(A[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=(dp[i-1][j] || dp[i-1][j-A[i-1]]);
        }
    }
    return dp[n][Sum];
}

bool equalPartition(vector<int>& A, int n){
    int Sum=0;
    for(int i=0; i<n; i++){
        Sum+=A[i];
    }
    if(Sum%2!=0)
        return false;
    else
        return sumSubset(A, n, Sum/2);
}

bool DPequalPartition(vector<int>& A, int n){
    int Sum=0;
    for(int i=0; i<n; i++){
        Sum+=A[i];
    }
    vector<vector<int>> dp2(n+1, vector<int> (Sum+1));
    for(int i=0; i<n; i++){
       for(int j=0;j<Sum+1;j++){
           dp2[i][j]=-1;
       }
    }
    if(Sum%2!=0)
        return false;
    else
        return topDownSubset(A, n, Sum/2, dp2);
}

int main(){
    vector<int> A={1,5,11,5};
    int n=A.size();
    cout<<equalPartition(A, n)<<endl;
    cout<<DPequalPartition(A, n)<<endl;
}
