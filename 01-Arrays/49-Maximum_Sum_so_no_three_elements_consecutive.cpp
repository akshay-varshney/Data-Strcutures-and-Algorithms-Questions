// Array: Maximum subsequence sum such that no three are consecutive
//https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/

#include<iostream>
#include<vector>
/*
 sum[0] = arr[0]

 // Note : All elements are positive
 sum[1] = arr[0] + arr[1]

 // We have three cases
 // 1) Exclude arr[2], i.e., sum[2] = sum[1]
 // 2) Exclude arr[1], i.e., sum[2] = sum[0] + arr[2]
 // 3) Exclude arr[0], i.e., sum[2] = arr[1] + arr[2]
 sum[2] = max(sum[1], arr[0] + arr[2], arr[1] + arr[2])

 In general,
 // We have three cases
 // 1) Exclude arr[i],  i.e.,  sum[i] = sum[i-1]
 // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
 // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]
 sum[i] = max(sum[i-1], sum[i-2] + arr[i],
              sum[i-3] + arr[i] + arr[i-1])
 */
using namespace std;


int maxSum(vector<int>& A, vector<int>& Sum){
    int n=A.size();
    if(n>=1)
        Sum[0]=A[0];
    if(n>=2)
        Sum[1]= A[0]+ A[1];
    if(n>2)
        Sum[2] = max(Sum[1], max(A[1]+ A[2] , A[0] + A[2]));
    for(int i=3;i<n;i++){
        Sum[i]= max(max(Sum[i-1], Sum[i-2] +A[i]), A[i] + A[i-1] + Sum[i-3]);
    }
    return Sum[n-1];
}


int main(){
    vector<int> A= {100, 1000, 100, 1000, 1};
    vector<int> Sum(A.size());
    cout<<maxSum(A, Sum)<<endl;
  
   
}

