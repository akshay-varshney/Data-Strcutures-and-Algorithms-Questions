// Matrix: Search Element in a Matrix
// https://leetcode.com/problems/search-a-2d-matrix/submissions/
/*
 Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 Output: true
 */
#include<iostream>
#include<vector>

using namespace std;

// Using Binary Search in Matrix
bool searchMatrix(vector<vector<int>>& A, int val)
{
    int n=A.size();
    int m=A[0].size();
    bool value=false;
    for(int i=0;i<n;i++){
        if(A[i][m-1]<val) continue;
        else if(A[i][0]>val) continue;
        else{
            int start=0;
            int end=m;
            while(start<=end){
                int mid=(start+end)/2;
                if(A[i][mid]==val)  return  true;
                else if(A[i][mid]>val) end=mid-1;
                else start=mid+1;
            }
        }
    }
    return value;
}


int main(){
    vector<vector<int>> v1={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchMatrix(v1, 13)<<endl;
}
