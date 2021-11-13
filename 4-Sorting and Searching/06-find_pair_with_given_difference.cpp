// Searching & Sorting: Find Pair with given Difference
//https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#

/*
 I/p: {3,1,3}
 o/p: 3,2
 */
#include<iostream>
#include<vector>
using namespace std;

// Need to find a pair without using extra space.
// 2 steps:
// 1. Sort the array
//2. Start finding difference if less increment end pointer otherwise increment start pointer.
bool pair_diff(vector<int> &A, int x){
    int n=A.size();
    int start=0;
    int end=1;
    sort(A.begin(),A.end());
    while(start<n && end<n){
        if(A[end]-A[start]==x){
            return true;
        }
        else if(A[end]-A[start]<x){
            end++;
        }
        else{
            start++;
        }
    }
    return false;
}
//Time: O(nlogn) Space: O(1)

int main(){
    vector<int> v1= {5, 20, 3, 2, 5, 80};
    cout<<pair_diff(v1, 78)<<endl;
}
