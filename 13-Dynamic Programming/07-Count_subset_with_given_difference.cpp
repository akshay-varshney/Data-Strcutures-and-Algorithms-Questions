// Dynamic Programming: Count the number of subset with a given difference

#include<iostream>
#include<vector>
using namespace std;


int topDownSubset(vector<int>& A, int n, int Sum, vector<vector<int>>& dp){
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=Sum;j++){
            if(j==0 && i==0)
                dp[i][j]=1;
            else if(i==0 && j!=0)
                dp[i][j]=0;
            else if(j==0 && i!=0)
                dp[i][j]=1;
            else if(A[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=(dp[i-1][j] + dp[i-1][j-A[i-1]]);
        }
    }
    return dp[n][Sum];
}

/*
 s1 - s2 = diff given
 s1 + s2=sum of array
Adding both
 2s1= diff + sum of array
 s1= (diff + sum of array)/2;
 
 */
int countWithGivenSum(vector<int>& A, int n, int diff)
{
     int Sum=0;
    for(int i=0;i<n;i++)
    {
        Sum+=A[i];
    }
     
     int reqSum=(diff+Sum)/2;
    vector<vector<int>> dp2(n+1, vector<int> (Sum+1));
            for(int i=0; i<n; i++){
                for(int j=0;j<Sum+1;j++){
                    dp2[i][j]=-1;
                }
            }
     return topDownSubset(A, n, reqSum, dp2);
}
int main(){
    vector<int> A={1,1,2,3};
    int n=A.size();
    int diff=1;
    cout<<countWithGivenSum(A, n, diff)<<endl;
}
