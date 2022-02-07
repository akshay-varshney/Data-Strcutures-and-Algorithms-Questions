// Array: Search in row and column wise sorted matrix

#include<iostream>
#include<vector>

using namespace std;

//Time: O(nlogn(n)) and Space:O(1)
int matSearch (vector<vector<int>> &A, int x){
    int n=A.size();
    int m=A[0].size();
    for(int i=0;i<n;i++){
        if(A[i][m-1]>=x && A[i][0]<=x){
            int start=0;
            int end=m;
            while(start<=end){
                int mid=(start+end)/2;
                if(A[i][mid]==x){
                    return 1;
                }
                else if(A[i][mid]>x){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
        }
    }
    return 0;
}

    
int main(){
    vector<vector<int>> v1={{3, 30, 38},{44, 52, 54},{57, 60, 69}};
    int value=54;
    cout<<matSearch(v1, value)<<endl;
    
}
