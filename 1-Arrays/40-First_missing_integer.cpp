// Array: Find first missing positive integer
// https://www.interviewbit.com/problems/first-missing-integer/
/*
 Given [1,2,0] return 3,

 [3,4,-1,1] return 2,
 */
#include<iostream>
#include<vector>

using namespace std;
int first_poitive(vector<int> &A){
    int n=A.size();
    int start=0;
    while(start<n){
        if(A[start]>0 && A[start]<=n){
            if(A[start]==A[A[start]-1]){
                start++;
            }
            else swap(A[start],A[A[start]-1]);
        }
        else start++;
    }
        for(int i=0;i<n;i++){
            if(A[i]==i+1) continue;
            else return i+1;
        }
    return 1;
}

int main(){
    vector<int> v1={1,1,1};
    cout<<first_poitive(v1)<<endl;
}
