// Array: Three way partitioning
// https://www.geeksforgeeks.org/three-way-partitioning-of-an-array-around-a-given-range/

#include<iostream>
#include<vector>

using namespace std;

void threeway(vector<int> &A, int a, int b){
    int start=0;
    int mid=0;
    int n=A.size();
    int end=n-1;
    while(mid<=end){
        if(A[mid]<a){
            swap(A[start],A[mid]);
            mid++;
            start++;
        }
        else if(A[mid]<=b) mid++;
        else if(A[mid]>b){
            swap(A[end], A[mid]);
            end--;
        }
    }
}
//Time: O(n) and Space: O(1)

int main(){
    vector<int> v1={76, 8, 75, 22, 59, 96, 30, 38, 36};
    int a=44;
    int b=62;
    threeway(v1, a, b);
}
