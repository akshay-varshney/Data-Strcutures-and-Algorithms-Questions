
// Dynamic Programming: Friend's Pair Problem
/*
 Variation of 0-1/KnapSack
 One person has two choices:
 1. Included in pair
 2. Remain Single
 
 Single would have : (n-1) choices
 Pair: (n-1)*(n-2) choices
 
 */
//https://www.geeksforgeeks.org/friends-pairing-problem/


#include<iostream>
#include<vector>
using namespace std;


// Method 1: Recursive
int recursivepair(int n){
    if(n<=2)
        return n;
    return recursivepair(n-1)+ (n-1)*recursivepair(n-2);
}
// Time: (2^n)


// Method 2: Memoization
int memoization_pair(int n, vector<int>& dp){
    if(n<=2)
        return dp[n]=n;
    return dp[n]= memoization_pair(n-1,  dp) + (n-1)*memoization_pair(n-2, dp);
}

// Method 3: Top Down
int topdown_pair(int n,  vector<int>& dp){
    for(int i=0;i<=n;i++)
    {
        if(i<=2)
            dp[i]=i;
        else
            dp[i]= dp[i-1]+(i-1)*dp[i-2];
        }
    return dp[n];
}

int main() {
    int n=4;
    cout<<"Recursive Value of pair: "<<recursivepair(n)<<endl;

    vector<int> dp(n+1);
    for(int i=0; i<n+1; i++)
    {
        dp[i]=-1;
    }
    
    cout<<"Memoization DP Value of pair: "<<memoization_pair(n, dp)<<endl;

    dp.clear();
    vector<int> dp2(n+1);
    for(int i=0; i<n+1; i++)
    {
        dp2[i]=-1;
    }
    cout<<"TopDown DP Value of pair: "<<topdown_pair(n, dp2)<<endl;
    dp2.clear();
}
