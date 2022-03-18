
// Dynamic Programming: Coin Change, Count all possibe way to make to the required Sum
// https://www.geeksforgeeks.org/coin-change-dp-7/


#include<iostream>
#include<vector>
using namespace std;

// Method 1: By using Recurssion
int coinchange(vector<int>& coin, int n, int Sum){
    if(Sum==0)
        return 1;
    if(n==0 && Sum!=0)
        return 0;
    if(coin[n-1]>Sum)
        return coinchange(coin, n-1, Sum);
    else
        return (coinchange(coin, n-1, Sum) + coinchange(coin, n, Sum-coin[n-1]));
}

// Method 2: By using Memoization
int memoizationcoinchange(vector<int>& coin, int n, int Sum, vector<vector<int>>& dp){
    if(Sum==0)
        return 1;
    if(n<=0)
        return 0;
    if(dp[n-1][Sum]!=-1)
        return dp[n-1][Sum];
    if(coin[n-1]>Sum){
        dp[n-1][Sum]= memoizationcoinchange(coin, n-1, Sum, dp);
        return dp[n-1][Sum];
    }
    else{
        dp[n-1][Sum]= (memoizationcoinchange(coin, n-1, Sum, dp) + memoizationcoinchange(coin, n, Sum- coin[n-1], dp));
        return dp[n-1][Sum];
    }
}

// Method 3: By using Top Down DP
int topDowncoinchange(vector<int>& coin, int n, int Sum, vector<vector<int>>& dp){
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=Sum;j++){
            if(j==0 && i==0)
                dp[i][j]=1;
            else if(i==0 && j!=0)
                dp[i][j]=0;
            else if(j==0 && i!=0)
                dp[i][j]=1;
            else if(coin[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=(dp[i-1][j] + dp[i][j-coin[i-1]]);
        }
    }
    return dp[n][Sum];
}


int main(){
    vector<int> coin={1,2,3};
    int Sum=4;
    int n=coin.size();
    cout<<coinchange(coin, n, Sum)<<endl;
    vector<vector<int>> dp(n+1, vector<int> (Sum+1));
        for(int i=0; i<n; i++){
            for(int j=0;j<Sum+1;j++){
                dp[i][j]=-1;
            }
        }
    cout<<memoizationcoinchange(coin, n, Sum, dp)<<endl;
    vector<vector<int>> dp2(n+1, vector<int> (Sum+1));
        for(int i=0; i<n; i++){
            for(int j=0;j<Sum+1;j++){
                dp2[i][j]=-1;
            }
        }
    cout<<topDowncoinchange(coin, n, Sum, dp2)<<endl;
    dp2.clear();
    dp.clear();
    
}
