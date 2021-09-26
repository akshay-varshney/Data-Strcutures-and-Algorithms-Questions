// Array: Rearrange array in alternating positive & negative items with O(1) extra space

// https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
/*

 Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
 output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}

*/
#include<vector>
#include<iostream>

using namespace std;

void rearrange(vector<int> &A){
    int n=A.size();
    int start=0;
    int mid=0;
    while(mid<n){
        if(start%2==0){
            if(A[start]<0) mid++;
            else{
                while(mid<n && A[start]>0){
                    if(A[mid]<0){
                        int temp=A[mid];
                        for(int j=mid;j>start;j--){
                            A[j]=A[j-1];
                        }
                        A[start]=temp;
                    }
                    mid++;
                }
            }
        }
        else{
            if(A[start]<0){
            swap(A[start],A[start+1]);
            mid++;
            }
        }
        start++;
    }
}
// Time Complexity: O(nlogn) and Space: O(1)
int main(){
    vector<int> v1={-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    rearrange(v1);
    for(auto it=v1.begin();it!=v1.end();it++){
        cout<<*it<<" ";
    }
  
}
