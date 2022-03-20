
// Dynamic Programming: Longest Common Substring
//https://www.geeksforgeeks.org/longest-common-substring-dp-29/


#include<iostream>
#include<vector>
using namespace std;


int topDownLCS(string A, string B, int n, int m, vector<vector<int>>& dp){
    int re=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j==0 || i==0)
                dp[i][j]=0;
            else if(A[i-1]==B[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                re= max(re, dp[i][j]);
            }
            else
                dp[i][j]=0;
        }
    }
    return re;
}


int main(){
    string A= "abcdxyz";
    string B= "abcd";
    int n=A.size();
    int m=B.size();
    vector<vector<int>> dp2(n+1, vector<int> (m+1));
    for(int i=0; i<=n; i++){
        for(int j=0;j<=m;j++){
            dp2[i][j]=-1;
        }
    }
    cout<<topDownLCS(A, B, n, m, dp2)<<endl;
    dp2.clear();
}
