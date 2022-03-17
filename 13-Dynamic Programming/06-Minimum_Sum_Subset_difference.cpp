// Dynamic Programming: Partition a set into two subsets such that the difference of subset sums is minimum
// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/p-18/


#include<iostream>
#include<vector>
using namespace std;

// Finding the subset array
void SubsetSumArray(vector<int>& A, int Sum, int n, vector<vector<bool>>& dp){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=Sum;j++){
            if(j==0)
                dp[i][j]=true;
            else if(i==0)
                dp[i][j]= false;
            else if(A[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-A[i-1]]);
        }
    }
}

// Steps:
/*
 1. Finding the Sum Range
 2. Invalidating all the values from DP table whose subset is not possible.
 3. If athe value of the subset is false then we'll not consider that as the subset array
 4. Finding the mini in only Sum/2 and finding the minimum from (0 to sum/2)
 */
int minimumSubsetDiff(vector<int>& A){
    int n=A.size();
    int Sum=0;
    for(int i=0; i<n; i++){
        Sum+=A[i];
    }
    vector<vector<bool>> dp(n+1, vector<bool> (Sum+1));
    SubsetSumArray(A, Sum, n, dp);
    int mini=INT_MAX;
    for(int i=0;i<=Sum/2; i++){
        if(dp[n][i]==true)
            mini=min(mini, Sum- 2*i);
    }
    return mini;
}

int main(){
    vector<int> A={3, 1, 4, 2, 2, 1};
    cout<<minimumSubsetDiff(A)<<endl;
}
