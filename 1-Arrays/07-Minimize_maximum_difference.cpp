//Array: Minimize the maximum difference between heights
// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

#include<iostream>

using namespace std;

// Modified Kadane’s Algorithm
int maximum_subarray(int arr[], int n, int k){
    sort(arr,arr+n);
    
    if (n<=0) return -1;
    int maxi=arr[n-1]-k;
    int mini=arr[0]+k;
    int val=arr[n-1]-arr[0];
    int x,y;
    for(int i=0;i<n-1;i++){
        x=min(mini,arr[i]-k);
        y=max(maxi,arr[i]+k);
        if(x<0){
            continue;
        }
        val=min(val,y-x);
    }
    return val;
}

int main(){
    int arr[] = {3, 9, 12, 16, 20};
    int n=sizeof(arr)/sizeof(arr[0]);
    std::cout<<maximum_subarray(arr, n,3)<<std::endl;
    
}


