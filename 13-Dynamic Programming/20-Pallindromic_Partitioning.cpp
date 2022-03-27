// Dynamic Programming: Palindrome Partitioning
//https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
// https://youtu.be/9h10fqkI7Nk?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go


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


// Method 1: By using Recurssion,
int palindromicpartition(string A, int i, int j){
    if(i>=j)
        return 0;
    if(isPlaindrome(A, i, j))
        return 0;
    int mini= INT_MAX;
    for(int k=i;k<j; k++){
        int temp= palindromicpartition(A, i, k)+ palindromicpartition(A, k+1, j) + 1;
        mini=min(mini,temp);
    }
    return mini;
}
// Time: O(2^n)



//
// Method 2: By using Memoization
int Memoizationpalindromicpartition(string A, int i, int j, vector<vector<int>>& dp){
    if(i>=j)
        return 0;
    if(isPlaindrome(A, i, j) )
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mini= INT_MAX;
    for(int k=i;k<j; k++){
        int temp= Memoizationpalindromicpartition(A, i, k, dp)+ Memoizationpalindromicpartition(A, k+1, j, dp) + 1;
        mini=min(mini,temp);
    }
    return dp[i][j]=mini;
}

// Method 3: By using Optimized Memoization
int optimizedMemoizationpalindromicpartition(string A, int i, int j, vector<vector<int>>& dp){
    if(i>=j)
        return 0;
    if(isPlaindrome(A, i, j) )
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mini= INT_MAX;
    for(int k=i;k<j; k++){
        int left, right;
        if(dp[i][k]!=-1)
            left=dp[i][k];
        else{
            left=optimizedMemoizationpalindromicpartition(A, i, k, dp);
            dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1)
            right=dp[k+1][j];
        else{
            right=optimizedMemoizationpalindromicpartition(A, k+1, j, dp);
            dp[k+1][j]=right;
        }
        int temp= left+ right + 1;
        mini=min(mini,temp);
    }
    return dp[i][j]=mini;
}
int main(){
    string A= "ababbbabbababa";
    int n=A.size();
    cout<<palindromicpartition(A, 0, n-1)<<endl;

    vector<vector<int>> dp(n+1, vector<int> (n+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<Memoizationpalindromicpartition(A,0,n-1,dp)<<endl;
    vector<vector<int>> dp2(n+1, vector<int> (n+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=n;j++){
            dp2[i][j]=-1;
        }
    }
    cout<<optimizedMemoizationpalindromicpartition(A, 0, n-1, dp2)<<endl;
    dp.clear();
    dp2.clear();
}


