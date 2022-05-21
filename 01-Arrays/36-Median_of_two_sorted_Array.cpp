// Array: Median of two sorted arrays of different sizes
// https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/

#include<iostream>
#include<vector>

using namespace std;

// Brute force by using linear search
int median_sorted(vector<int> &A, vector<int> &B){
    int n=A.size();
    int m=B.size();
    int x=n+m;
    int x1=0;
    if(x%2==0) x1=(x/2);
    else  x1=(x+1)/2;
    int count=0;
    int s1=0,s2=0;
    int val=0;
    //Traversing the both array until we find the required element
    while(s1<n && s2<m && count<x1){
        if(A[s1]<B[s2]){
            val=A[s1];
            s1++;
        }
        else{
            val=B[s2];
            s2++;
        }
        count++;
    }
    if(count<x1){
        while(s1<n && count<x1){
            val=A[s1];
            s1++;
            count++;
        }
        while(s2<m && count<x1){
            val=B[s2];
            s2++;
            count++;
        }
    }
    if (x%2==0){
        int value=0;
        if(s1<n && s2<m && A[s1]<B[s2]) value=A[s1];
        else if(s1<n && A[s1]<B[s2]) value=A[s1];
        else value=B[s2];
        return (val+value)/2;
    }
    return val;
}
//Time: O(m+n) and space: O(1)

// By using Binary Search and Partitioning the Array:
/*
 Partitioning the array in such a way such that all the elemnets on the left are lesser than all the elements on the right side.
 */
double median_binary(vector<int> &A, vector<int> &B){
    int n=A.size();
    int m=B.size();
    //here we are partitoning using A
    if(n>m){
        median_sorted(B, A);
    }
    int start=0;
    int end=n;
    while(start<=end){
        // Partition point for x
        int partition_x=start+end/2;
        int partition_y=(m+n+1)/2-partition_x;
        int max_left_1,min_right_1,max_left_2,min_right_2;
        // if no partition is left then we are replacing it with INT_MIN and INT_MAX
        if(partition_x==0) max_left_1=INT_MIN;
        else max_left_1=A[partition_x-1];
        if(partition_x==0) min_right_1=INT_MAX;
        else min_right_1=A[partition_x];
        if(partition_y==0) max_left_2=INT_MIN;
        else max_left_2=B[partition_y-1];
        if(partition_y==0) min_right_2=INT_MAX;
        else min_right_2=B[partition_y];
        if(max_left_1<=min_right_2 && max_left_2<=min_right_1){
            if((m+n)%2==0){
                double val=(max(max_left_1,max_left_2)+min(min_right_1,min_right_2))/2;
                return val;
            }
            else{
                return max(max_left_2,max_left_1);
            }
        }
        else if(max_left_1>min_right_2){
            end=partition_x-1;
        }
        else{
            start=partition_x+1;
        }
        
    }
    return 0;
}

int main(){
    vector<int> v1={-5, 3, 6, 12, 15};
    vector<int> v2={-12, -10, -6, -3, 4, 10};
    cout<<median_sorted(v1, v2)<<endl;
    cout<<median_binary(v1, v2)<<endl;
}
