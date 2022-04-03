// Array: Maximum Sum of Longest Increasing Subsequence
//https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

// Method 1: By using another vector and storing the previous count of longest increasing Subsequence
int longestIncreasingSubse(vector<int>& A){
    int n=A.size();
    vector<int> SubsequenceVal(n);
    for(int i=0;i<n;i++){
        SubsequenceVal[i]=A[i];
    }
    for(int i=1; i<n; i++){
        for(int j=0;j<i;j++){
            if(A[i]> A[j] && SubsequenceVal[i]< SubsequenceVal[j]+ A[i])
                SubsequenceVal[i]= SubsequenceVal[j]+A[i];
        }
    }
    int maxi= SubsequenceVal[0];
    for(int i=1;i<n;i++){
        maxi=max(maxi, SubsequenceVal[i]);
    }
    return maxi;
}



int main(){
    vector<int> A= {1, 101, 2, 3, 100};
    cout<<"Sum of Longest Increasing Subsequence  is: "<<longestIncreasingSubse(A)<<endl;
   
}

