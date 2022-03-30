
// Dynamic Programming: Egg Dropping Puzzle
//https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

#include<iostream>
#include<vector>
using namespace std;

bool isPlaindrome(string A, int i, int j){
    while(i<j){
        if(A[i]!=A[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// In this Question, we need to find the minimum number of attempts to find the threshold floor, so to get the threshold floor in min attempts we'll take maximum of worst case and then find the minimum from all.

// Method 1: By using Recurssion,
int recursiveEggdrop(int e, int f){
    if(f==0 || f==1)
        return f;
    if(e==0)
        return f;
    int mini= INT_MAX;
    for(int k=1;k<=f; k++){
        int temp= max(recursiveEggdrop(e-1, k-1), recursiveEggdrop(e,f-k)) + 1;
        mini=min(mini,temp);
    }
    return mini;
}
// Time: O(2^n)



//
// Method 2: By using Memoization
int MemoizationEggdrop(int e, int f, vector<vector<int>>& dp){
    if(f==0 || f==1)
        return dp[e][f]=f;
    if(e==0)
        return dp[e][f]=f;
    if(dp[e][f]!=-1)
        return dp[e][f];
    int mini= INT_MAX;
    for(int k=1;k<=f; k++){
        int temp= max(MemoizationEggdrop(e-1, k-1, dp), MemoizationEggdrop(e, f-k, dp)) + 1;
        mini=min(mini,temp);
    }
    return dp[e][f]=mini;
}


// Method 3: By using Memoization
int optimizedMemoizationEggdrop(int e, int f, vector<vector<int>>& dp){
    if(f==0 || f==1)
        return dp[e][f]=f;
    if(e==0)
        return dp[e][f]=f;
    if(dp[e][f]!=-1)
        return dp[e][f];
    int mini= INT_MAX;
    for(int k=1;k<=f; k++){
        int left, right;
        if(dp[e-1][k-1]!=-1)
            left=dp[e-1][k-1];
        else
        {
            left=optimizedMemoizationEggdrop(e-1, k-1, dp);
            dp[e-1][k-1]=left;
        }
        if(dp[e][f-k]!=-1)
            right=dp[e][f-k];
        else{
            right=optimizedMemoizationEggdrop(e, f-k, dp);
            dp[e][f-k]=right;
        }
        int temp= max(left, right) + 1;
        mini=min(mini,temp);
    }
    return dp[e][f]=mini;
}
int main(){
    int f= 10;
    int e=2;
    cout<<recursiveEggdrop(e, f)<<endl;

    vector<vector<int>> dp(f+1, vector<int> (e+1));
    for(int i=0; i<=e; i++){
        for(int j=0;j<=f;j++){
            dp[i][j]=-1;
        }
    }
    cout<<MemoizationEggdrop(e,f,dp)<<endl;
    dp.clear();
    
    vector<vector<int>> dp2(f+1, vector<int> (e+1));
    for(int i=0; i<=e; i++){
        for(int j=0;j<=f;j++){
            dp2[i][j]=-1;
        }
    }
    cout<<optimizedMemoizationEggdrop(e,f,dp2)<<endl;
    dp2.clear();
}

