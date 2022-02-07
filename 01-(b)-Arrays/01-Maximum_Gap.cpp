// Array: Max Distance
// https://www.interviewbit.com/problems/max-distance/
/*
 Input: A = [3, 5, 4, 2]
 O/p: 2
 
 A[i] <= A[j] and j>=i
 */
#include<iostream>
#include<vector>

using namespace std;

// using suffix and prefix array. Prefix will store the minimum till now and suffix will store the maximum till now
int maximum_gap(vector<int> &A){
    int n=A.size();
    int start=0;
    int end=n-1;
    vector<int> min_left(n);
    vector<int> max_right(n);
    min_left[0]=A[0];
    for(int i=1;i<n;i++){
        min_left[i]=min(A[i],min_left[i-1]);
    }
    max_right[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--){
        max_right[i]=max(max_right[i+1],A[i]);
    }
    int i=0, j=0, max_diff=-1;
    while(i<n && j<n){
        if(max_right[j]-min_left[i]>=0){
            max_diff=max(max_diff,j-i);
            j++;
        }
        else i++;
    }
    return max_diff;
}
// Time: O(n) and Space: O(n)

int main(){
    vector<int> v1={6,2,5,4,1,1,1,3};
    cout<<"Maximum Gap: "<< maximum_gap(v1)<<endl;
}
