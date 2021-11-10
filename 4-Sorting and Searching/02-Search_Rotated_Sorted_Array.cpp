// Searching:Search in a rotated sorted array
//https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/

#include<iostream>
#include<vector>

using namespace std;

int rotated_search(vector<int> A, int x){
    int inv=1;
    int n=A.size();
    if(n<3){
        for(int i=0;i<n;i++){
            if(A[i]==x){
                return i;
            }
        }
        return -1;
    }
    // Finding the inversion point of rotation
    bool flag=false;
    for(int i=1;i<n-1;i++){
        if(A[i]<A[i-1] && A[i]<A[i+1]){
            inv=i;
            flag=true;
            break;
        }
    }
    if(A[n-1]<A[0] && flag!=true){
        inv=n-1;
    }
    //traversing in two parts from inversion point to end and from start to inversion point
    int start1=0;
    int end1=inv-1;
    int start2=inv;
    int end2=n-1;
    while(start1<=end1){
        int mid=(start1+end1)/2;
        if(A[mid]==x){
            return mid;
        }
        else if(A[mid]>x){
            end1=mid-1;
        }
        else{
            start1=mid+1;
        }
    }
    while(start2<=end2){
        int mid=(start2+end2)/2;
        if(A[mid]==x){
            return mid;
        }
        else if(A[mid]>x){
            end2=mid-1;
        }
        else{
            start2=mid+1;
        }
    }
    return -1;
}
//Time: O(nlogn) and Space:O(1)

int main(){
    vector<int> A={5,1,3};
    cout<<rotated_search(A, 1);
}
