// Dynamic Programming: 0/1 Knapsack
/*
 Input:
 Weights: { 2, 3, 1, 4 }
 Profits: { 4, 5, 3, 7 }
 Knapsack capacity: 5
 
 O/p: 10
 */
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/


#include<iostream>
#include<vector>
using namespace std;

//int max(int a, int b) { return (a > b) ? a : b; }

// Method 1: Normal recurssion.
// recursive call after choosing the element at the currentIndex
// if the weight of the element at currentIndex exceeds the capacity, we shouldn't process this
int knapScak(int w, vector<int>& wt, vector<int>& profit, int n){
    if(n==0 || w==0)
        return 0;
    if(wt[n]> w)
        return knapScak(w, wt, profit, n-1);
    else
        return max((knapScak(w, wt, profit, n-1)), (profit[n]+knapScak(w-wt[n], wt, profit, n-1)));
}
// Time: 2^n


// Method 2: Dynamic Programming with Memoization
int MemoizationknapScak(int w, vector<int>& wt, vector<int>& profit, int n, vector<vector<int>>& dp){
    //if we have already solved a similar problem, return the result from memory
    if(dp[n][w]!=-1)
        return dp[n][w];
    if(n==0 || w==0)
        return 0;
    if(wt[n]> w){
        dp[n][w]=MemoizationknapScak(w, wt, profit, n-1, dp);
        return dp[n][w];
    }
    //recursive call after excluding the element at the currentIndex
    else{
        dp[n][w]= max((MemoizationknapScak(w, wt, profit, n-1, dp)), (profit[n]+MemoizationknapScak(w-wt[n], wt, profit, n-1, dp)));
        return dp[n][w];
    }

}

// Method 3: Dynamic Programming with Tabulation
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
    return dp[n-1][w];
}


int main() {
    vector<int> wt={3,2,4};
    vector<int> profit= {6,8,7};
    int w=8;
    int n=profit.size()+1;
    cout<<"Maximum Profit is: "<<knapScak(w, wt, profit, n-1)<<endl;
    vector<vector<int>> dp(n, vector<int> (w+1));
    for(int i=0; i<n; i++){
        for(int j=0;j<w+1;j++){
            dp[i][j]=-1;
        }
    }
    
    cout<<"Maximum Profit is: "<<MemoizationknapScak(w, wt, profit, wt.size()-1, dp)<<endl;
    cout<<"Maximum Profit is: "<<tabulationKnapsack(w, wt, profit, wt.size(), dp)<<endl;
    dp.clear();
}
