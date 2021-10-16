// Array: Find maximum sum of triplets in an array such than i < j < k and a[i] < a[j] < a[k]
//https://www.interviewbit.com/problems/maximum-sum-triplet/

// Input:  A = [2, 5, 3, 1, 4, 9]
//   Maximum sum = 16

#include<vector>
#include<iostream>

using namespace std;

// Method 1: Finding maximum in left and right side of the array.
// Time Complexity: O(n^2) and space is O(1)
int max_sum(vector<int> & A){
    int ans=0;
    int n=A.size();
    int max_1=INT_MIN;
    int max_2=INT_MIN;
    for(int i=1;i<n-1;i++){
        max_1=0;
        max_2=0;
        for(int j=0;j<i;j++){
            if(A[j]<A[i]){
                max_1=max(max_1,A[j]);
            }
        }
        for(int j=i+1;j<n;j++){
            if(A[j]>A[i]){
                max_2=max(max_2,A[j]);
            }
        }
        if(max_1 && max_2){
            ans=max(ans,A[i]+max_1+max_2);
        }
    }
    return ans;
}


int main(){
    vector<int> v1={2, 5, 3, 1, 4, 9};
    cout<<max_sum(v1)<<endl;
}
