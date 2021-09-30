// Array: Chocolate Distribution Problem
// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

/*
 Input:
 N = 7, M = 3
 A = {7, 3, 2, 4, 9, 12, 56}
 Output: 2
 */

#include<iostream>
#include<vector>

using namespace std;

int minimum_difference(vector<int> &A, int m){
    int n=A.size();
    if (n<m) return -1;
    sort(A.begin(),A.end());
    int i=0;
    int k=i+m-1;
    int minimum_diff=INT_MAX;
    while(k<n){
        minimum_diff=min(minimum_diff,A[k]-A[i]);
        i++;
        k++;
    }
    return minimum_diff;
}
// Time: O(nlogn) Space:O(1)

int main(){
    vector<int> v1={7, 3, 2, 4, 9, 12, 56};
    cout<<minimum_difference(v1, 3)<<endl;
    
}
