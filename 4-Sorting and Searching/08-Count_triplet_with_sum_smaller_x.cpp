// Searching & Sorting: Count triplets with sum smaller than X
//https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1#

#include<iostream>
#include<vector>
using namespace std;

int counttriplets(vector<int> &A, int x){
    int n=A.size();
    int count=0;
    if(n<3) return 0;
    sort(A.begin(),A.end());
    for(int i=0;i<n-2;i++){
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            if (A[i] + A[j] + A[k] >=x ){
                k--;
            }
            else
            {
                count += (k - j);
                j++;
            }
        }
    }
    return count;
}
//Time: O(n2) and Space: O(1)

int main(){
    vector<int> v1= {5, 1, 3, 4, 7};
    cout<<counttriplets(v1, 12)<<endl;
}
