// Dynamic Programming: Fibonaci Example of what is dynamic Programming.
/*
 condition to apply DP:
1.  Optimal Substructure: by solving sub problems we should be able to get the result of the entire problem.
 2. Repeating sub problems.
 */

#include<iostream>
#include<vector>
using namespace std;

// Method 1: Normal recurssion.
int recurssionFibo(int n){
    if(n<=1)
        return n;
    else
        return recurssionFibo(n-1)+ recurssionFibo(n-2);
}


// Method 2: by using Dynamic Programming and reusing the last result apart from calculating it again.
int dpFibo(int n){
    vector<int> dp(n);
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    int n=4;
    cout<<recurssionFibo(n)<<endl;
    cout<<dpFibo(n)<<endl;
}
