// Dynamic Programming: Fibonaci Example of what is dynamic Programming.
/*
 condition to apply DP:
1.  Optimal Substructure: by solving sub problems we should be able to get the result of the entire problem.
 2. Repeating sub problems.
 */

#include<iostream>
#include<vector>
using namespace std;

//int max(int a, int b) { return (a > b) ? a : b; }

// Method 1: Normal recurssion.
int knapScak(int w, vector<int>& wt, vector<int>& profit, int n){
    if(n==0 || w==0)
        return 0;
    if(wt[n]> w)
        return knapScak(w, wt, profit, n-1);
    else
        return max((knapScak(w, wt, profit, n-1)), (profit[n]+knapScak(w-wt[n], wt, profit, n-1)));
}

int MemoizationknapScak(int w, vector<int>& wt, vector<int>& profit, int n, vector<vector<int>>& dp){
    if(dp[n][w]!=-1)
        return dp[n][w];
    if(n==0 || w==0)
        return 0;
    if(wt[n]> w){
        dp[n][w]=MemoizationknapScak(w, wt, profit, n-1, dp);
        return dp[n][w];
    }
    else{
        dp[n][w]= max((MemoizationknapScak(w, wt, profit, n-1, dp)), (profit[n]+MemoizationknapScak(w-wt[n], wt, profit, n-1, dp)));
        return dp[n][w];
    }

}

int tabulationKnapsack(int w, vector<int>& wt, vector<int>& profit, int n, vector<vector<int>>& dp){
    for(int i=0;i<n;i++){
        for(int j=0;j<w;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(wt[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]= max(dp[i-1][j], profit[i-1]+dp[i-1][w-wt[i-1]]);
        }
    }
    return dp[n][w];
}


int main() {
    vector<int> wt={3,2,4};
    vector<int> profit= {6,8,7};
    int w=8;
    int n=profit.size()+1;
    cout<<knapScak(w, wt, profit, n-1)<<endl;
    vector<vector<int>> dp(n, vector<int> (w+1));
    for(int i=0; i<n; i++){
        for(int j=0;j<w+1;j++){
            dp[i][j]=-1;
        }
    }
    
    cout<<MemoizationknapScak(w, wt, profit, wt.size()-1, dp)<<endl;
    cout<<tabulationKnapsack(w, wt, profit, wt.size()-1, dp)<<endl;
}
