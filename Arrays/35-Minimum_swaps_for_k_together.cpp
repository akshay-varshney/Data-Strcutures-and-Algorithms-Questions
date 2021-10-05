// Array: Minimum swaps and K together
//https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1#

#include<iostream>
#include<vector>

using namespace std;

// Brute force approach
int minimum_swaps(vector<int> &A, int k){
    int count=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(A[i]<=k){
            count++;
        }
    }
    int min_swap=INT_MAX;
    int ct=0;
    if (count<=1) return 0;
    if(count==n) return 0;
    int start=0;
    int end=count;
    while (end<=n) {
        ct=0;
        for(int i=start;i<end;i++){
            if(A[i]>k){
                ct++;
            }
        }
        min_swap=min(min_swap,ct);
        end++;
        start++;
    }
    return min_swap;
}
// Time: O(n2) and space: O(1) Brute force


// Sliding window technique
int opti_minimum_swaps(vector<int> &A, int k){
    int count=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(A[i]<=k){
            count++;
        }
    }
    int min_swap=INT_MAX;
    int ct=0;
    if (count<=1) return 0;
    if(count==n) return 0;
    int start=0;
    int end=count;
    for(int i=start;i<end;i++){
        if(A[i]>k){
            ct++;
        }
    }
   
    min_swap=min(min_swap,ct);
    while (end<n) {
        if(A[end]>k){
            ct++;
        }
        if(A[start]>k){
            ct--;
        }
        min_swap=min(min_swap,ct);
        end++;
        start++;
    }
    return min_swap;
}
// Time: O(n) and space: O(1)

int main(){
    vector<int> v1={19, 19, 12, 1, 20, 1};
    int k=1;
    cout<<minimum_swaps(v1, k)<<endl;
    cout<<opti_minimum_swaps(v1, k)<<endl;
}
