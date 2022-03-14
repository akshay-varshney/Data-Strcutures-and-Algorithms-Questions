// Dynamic Programming: Count of Subset with equal Sum
// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/


#include<iostream>
#include<vector>
using namespace std;

// Method 1: By using Recurssion
int sumSubset(vector<int>& A, int n, int Sum){
    if(Sum==0)
        return 1;
    if(n==0 && Sum!=0)
        return 0;
    if(A[n-1]>Sum)
        return sumSubset(A, n-1, Sum);
    else
        return (sumSubset(A, n-1, Sum) + sumSubset(A, n-1, Sum-A[n-1]));
}

// Method 2: By using Memoization
int memoizationSubset(vector<int>& A, int n, int Sum, vector<vector<int>>& dp){
    if(Sum==0)
        return 1;
    if(n<=0)
        return 0;
    if(dp[n-1][Sum]!=-1)
        return dp[n-1][Sum];
    if(A[n-1]>Sum){
        dp[n-1][Sum]= memoizationSubset(A, n-1, Sum, dp);
        return dp[n-1][Sum];
    }
    else{
        dp[n-1][Sum]= (memoizationSubset(A, n-1, Sum, dp) + memoizationSubset(A, n-1, Sum- A[n-1], dp));
        return dp[n-1][Sum];
    }
}

// Method 3: By using Top Down DP
int topDownSubset(vector<int>& A, int n, int Sum, vector<vector<int>>& dp){
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=Sum;j++){
            if(j==0 && i==0)
                dp[i][j]=1;
            else if(i==0 && j!=0)
                dp[i][j]=0;
            else if(j==0 && i!=0)
                dp[i][j]=1;
            else if(A[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=(dp[i-1][j] + dp[i-1][j-A[i-1]]);
        }
    }
    return dp[n][Sum];
}


int main(){
    vector<int> A={3,3,3,3};
    int Sum=6;
    int n=A.size();
    cout<<sumSubset(A, n, Sum)<<endl;
    vector<vector<int>> dp(n+1, vector<int> (Sum+1));
        for(int i=0; i<n; i++){
            for(int j=0;j<Sum+1;j++){
                dp[i][j]=-1;
            }
        }
    cout<<memoizationSubset(A, n, Sum, dp)<<endl;
    vector<vector<int>> dp2(n+1, vector<int> (Sum+1));
        for(int i=0; i<n; i++){
            for(int j=0;j<Sum+1;j++){
                dp2[i][j]=-1;
            }
        }
    cout<<topDownSubset(A, n, Sum, dp2)<<endl;
    dp2.clear();
    dp.clear();
    
}
