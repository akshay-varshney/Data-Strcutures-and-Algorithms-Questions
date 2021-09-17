// Array: Largest Sum Contiguous Subarray
// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/



#include<iostream>

using namespace std;

// Kadane’s Algorithm
int maximum_subarray(int arr[], int n){
    if (n<=0) return -1;
    int max_sum=INT_MIN;
    int summed=0;
    for(int i=0;i<n;i++){
        summed+=arr[i];
        if(summed<0){
            summed=0;
        }
        max_sum=max(max_sum,summed);
    }
    return max_sum;
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n=sizeof(arr)/sizeof(arr[0]);
    std::cout<<maximum_subarray(arr, n)<<std::endl;
    
}


