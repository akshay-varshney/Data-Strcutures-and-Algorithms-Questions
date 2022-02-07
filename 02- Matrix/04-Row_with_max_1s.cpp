// Matrix: Row with max 1s
//https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#
/*
 Arr[][] = {{0, 1, 1, 1},
            {0, 0, 1, 1},
            {1, 1, 1, 1},
            {0, 0, 0, 0}}
 Output: 2
 */
#include<iostream>
#include<vector>

using namespace std;

// Using Binary Search in Matrix
int Max_zero(vector<vector<int>>& A)
{
    int n=A.size();
    int m=A[0].size();
    int val;
    int max_0=0;
    for(int i=0;i<n;i++){
        if(A[i][m-1]==0) continue;
        else if(A[i][0]==1) return i;
        else{
            int start=0;
            int end=m;
            while(start<=end){
                int mid=(start+end)/2;
                if(A[i][mid]==1)  end=mid-1;
                else if(A[i][mid]==0) start=mid+1;
            }
            if(m-start>max_0){
                max_0=m-start;
                val=i;
            }
        }
    }
    return val;
}
// Time: O(n*log(m)) and Space: O(1)


int main(){
    vector<vector<int>> v1={{0, 1, 1, 1},{0, 0, 1, 1},{1, 1, 1, 1},{0, 0, 0, 0}};
    cout<<Max_zero(v1)<<endl;
}
