// DynamiC Programming: Rod Cutting Problem

//https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

#include<iostream>
#include<vector>
using namespace std;


// Method 1: Normal recurssion.
// recursive call after choosing the element at the currentIndex
// if the weight of the element at currentIndex exceeds the capacity, we shouldn't process this
int cutRodRecursive(int w, vector<int>& len, vector<int>& profit, int n){
    if(n==0 || w==0)
        return 0;
    if(len[n-1]> w)
        return cutRodRecursive(w, len, profit, n-1);
    else
        return max((cutRodRecursive(w, len, profit, n-1)), (profit[n-1]+cutRodRecursive(w-len[n-1], len, profit, n))); // here as have unlimited access if element is accpeted to we'll not decrease the n value
}
// Time: 2^n


// Method 2: Dynamic Programming with Memoization
int cutRodMemoization(int w, vector<int>& len, vector<int>& profit, int n, vector<vector<int>>& dp){
    //if we have already solved a similar problem, return the result from memory
    if(n<0)
        return 0;
    
    if(dp[n][w]!=-1)
        return dp[n][w];
    if(len[n]> w){
        dp[n][w]=cutRodMemoization(w, len, profit, n-1, dp);
        return dp[n][w];
    }
    //recursive call after excluding the element at the currentIndex
    else{
        dp[n][w]= max((cutRodMemoization(w, len, profit, n-1, dp)), (profit[n]+cutRodMemoization(w-len[n], len, profit, n, dp)));
        return dp[n][w];
    }

}

// Method 3: Dynamic Programming with Tabulation
int cutRodTabulation(int w, vector<int>& len, vector<int>& profit, int n, vector<vector<int>>& dp){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(len[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]= max(dp[i-1][j], profit[i-1]+dp[i][j-len[i-1]]);
        }
    }
    return dp[n][w];
}


int main() {
    vector<int> len;
    vector<int> profit= {1, 5, 8, 9, 10, 17, 17, 20};
    int w=profit.size();
    int n=profit.size();
    for(int i=0;i<n;i++){
        len.push_back(i+1);
    }
    
    cout<<"Maximum Profit is: "<<cutRodRecursive(w, len, profit, n)<<endl;
    vector<vector<int>> dp(n+1, vector<int> (w+1));
    for(int i=0; i<n+1; i++){
        for(int j=0;j<w+1;j++){
            dp[i][j]=-1;
        }
    }
    
    cout<<"Maximum Profit is: "<<cutRodMemoization(w, len, profit, n-1, dp)<<endl;
    dp.clear();
    vector<vector<int>> dp2(n+1, vector<int> (w+1));
    for(int i=0; i<n+1; i++){
        for(int j=0;j<w+1;j++){
            dp2[i][j]=-1;
        }
    }

    cout<<"Maximum Profit is: "<<cutRodTabulation(w, len, profit, n, dp2)<<endl;
    dp2.clear();
}
