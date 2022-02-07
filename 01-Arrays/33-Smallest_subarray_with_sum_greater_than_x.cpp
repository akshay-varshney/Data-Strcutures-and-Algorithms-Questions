// Array: Smallest subarray with sum greater than x
// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

/*
 Input:
 A[] = {1, 10, 5, 2, 7}
    x  = 9
 Output: 1
 */

#include<iostream>
#include<vector>

using namespace std;

int smallest_subaaray(vector<int> &A, int x){
    int n=A.size();
    if(x<A[0]) return 1;
    else if(x<A[n-1]) return 1;
    int max_count=INT_MAX;
    int i=0;
    int k=1;
    int summed=A[i]+A[k];
    while(k<n){
        if(summed>x){
            max_count=min(max_count,(k-i+1));
            summed-=A[i];
            i++;
        }
        else{
            k++;
            summed+=A[k];
        }
    }
    return max_count;
}
// Time: O(n) Space:O(1)

int main(){
    vector<int> v1={1, 10, 5, 2, 7};
    cout<<smallest_subaaray(v1, 9)<<endl;
}
