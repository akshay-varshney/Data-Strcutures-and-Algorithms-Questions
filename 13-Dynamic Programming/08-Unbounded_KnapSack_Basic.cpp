// DynamiC Programming: Unbounded KnapSack
// here we are allowed to use unlimited number  of instances of an item.
//https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/

#include<iostream>
#include<vector>
using namespace std;


// Method 1: Normal recurssion.
// recursive call after choosing the element at the currentIndex
// if the weight of the element at currentIndex exceeds the capacity, we shouldn't process this
int unboundedKnapSack(int w, vector<int>& wt, vector<int>& profit, int n){
    if(n==0 || w==0)
        return 0;
    if(wt[n-1]> w)
        return unboundedKnapSack(w, wt, profit, n-1);
    else
        return max((unboundedKnapSack(w, wt, profit, n-1)), (profit[n-1]+unboundedKnapSack(w-wt[n-1], wt, profit, n))); // here as have unlimited access if element is accpeted to we'll not decrease the n value
}
// Time: 2^n


// Method 2: Dynamic Programming with Memoization
int MemoizationUnboundedknapScak(int w, vector<int>& wt, vector<int>& profit, int n, vector<vector<int>>& dp){
    //if we have already solved a similar problem, return the result from memory
    if(n<0)
        return 0;
    
    if(dp[n][w]!=-1)
        return dp[n][w];
    if(wt[n]> w){
        dp[n][w]=MemoizationUnboundedknapScak(w, wt, profit, n-1, dp);
        return dp[n][w];
    }
    //recursive call after excluding the element at the currentIndex
    else{
        dp[n][w]= max((MemoizationUnboundedknapScak(w, wt, profit, n-1, dp)), (profit[n]+MemoizationUnboundedknapScak(w-wt[n], wt, profit, n, dp)));
        return dp[n][w];
    }

}

// Method 3: Dynamic Programming with Tabulation
int unboundedKnapSack(int w, vector<int>& wt, vector<int>& profit, int n, vector<vector<int>>& dp){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(wt[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]= max(dp[i-1][j], profit[i-1]+dp[i][j-wt[i-1]]);
        }
    }
    return dp[n][w];
}


int main() {
    vector<int> wt={1, 50};
    vector<int> profit= {1, 30};
    int w=100;
    int n=profit.size();
    cout<<"Maximum Profit is: "<<unboundedKnapSack(w, wt, profit, n)<<endl;
    vector<vector<int>> dp(n+1, vector<int> (w+1));
    for(int i=0; i<n+1; i++){
        for(int j=0;j<w+1;j++){
            dp[i][j]=-1;
        }
    }
    
    cout<<"Maximum Profit is: "<<MemoizationUnboundedknapScak(w, wt, profit, n-1, dp)<<endl;
    dp.clear();
    vector<vector<int>> dp2(n+1, vector<int> (w+1));
    for(int i=0; i<n+1; i++){
        for(int j=0;j<w+1;j++){
            dp2[i][j]=-1;
        }
    }

    cout<<"Maximum Profit is: "<<unboundedKnapSack(w, wt, profit, n, dp2)<<endl;
    dp2.clear();
}
