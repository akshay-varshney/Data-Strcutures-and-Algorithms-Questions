
// Dynamic Programming: Binomial Coefficient
/*
 C(n, k) = C(n-1, k-1) + C(n-1, k)
    C(n, 0) = C(n, n) = 1
 
 */
// https://www.geeksforgeeks.org/binomial-coefficient-dp-9/


#include<iostream>
#include<vector>
using namespace std;


// Method 1: Recursive
int recursivenCr(int n, int r){
    if(r>n)
        return 0;
    if(r==0 || r==n)
        return 1;
    return recursivenCr(n-1, r-1)+ recursivenCr(n-1, r);
}
// Time: (2^n)


// Method 2: Memoization
int memoization_nCR(int n, int r, vector<vector<int>>& dp){
    if(r>n)
        return dp[n][r]=0;
    if(r==0 || r==n)
        return dp[n][r]=1;
    if(dp[n][r]!=-1)
        return dp[n][r];
    return dp[n][r]= memoization_nCR(n-1, r-1, dp) + memoization_nCR(n-1, r, dp);
}

// Method 3: Top Down
int topdown_nCR(int n, int r, vector<vector<int>>& dp){
    for(int i=0;i<=n;i++){
        for(int j=0; j<=r; j++){
            if(j>i)
                dp[i][j]=0;
            else if(j==0 || j==i)
                dp[i][j]=1;
            else
                dp[i][j]= dp[i-1][j-1]+dp[i-1][j];
        }
    }
    return dp[n][r];
}

int main() {
    int n=5;
    int r=2;
    cout<<"Recursive Value of nCr: "<<recursivenCr(n, r)<<endl;

    vector<vector<int>> dp(n+1, vector<int> (r+1));
    for(int i=0; i<n+1; i++){
        for(int j=0;j<r+1;j++){
            dp[i][j]=-1;
        }
    }
    cout<<"Memoization DP Value of nCr: "<<memoization_nCR(n, r, dp)<<endl;

    dp.clear();
    vector<vector<int>> dp2(n+1, vector<int> (r+1));
    for(int i=0; i<n+1; i++){
        for(int j=0;j<r+1;j++){
            dp2[i][j]=-1;
        }
    }
    cout<<"TopDown DP Value of nCr: "<<topdown_nCR(n, r, dp2)<<endl;
    dp2.clear();
}
