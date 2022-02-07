// Array: Triplet Sum in Array
// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#
#include<iostream>
#include<vector>

using namespace std;

bool triplet_sum(vector<int> &A, int val){
    int n=A.size();
    if(n<3) return false;
    sort(A.begin(),A.end());
    int mid,end;
    for(int i=0;i<n-2;i++){
        mid=i+1;
        end=n-1;
        while (mid<end) {
            if(A[i]+A[mid]+A[end]==val) return true;
            else if(A[i]+A[mid]+A[end]<val) mid++;
            else end--;
        }
    }
    return false;
}
// Time: O(n2) and Space:O(1)

int main(){
    vector<int> v1={1, 2, 4, 3, 6};
    int x=10;
    cout<<triplet_sum(v1, x)<<endl;
}
