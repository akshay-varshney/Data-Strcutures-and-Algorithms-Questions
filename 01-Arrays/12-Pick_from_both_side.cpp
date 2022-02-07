
// Array: pick from both side and find maximum sum
// https://www.interviewbit.com/problems/pick-from-both-sides/

#include<iostream>

using namespace std;
// Method : Here we have to focus on eliminating the pair of size (n-B) which have minimum value. The remaining contigous elemnet will have a maximum sum
int max_sum(int arr[], int n, int B){
    int _sum=0;
    //overall sum of array
    for(int i=0;i<n;i++){
        _sum+=arr[i];
    }
    int j=n-B-1, i=0;
    int mini;
    int val=0;
    // sum of elements 0-k
    for(int k=0;k<=j;k++){
        val+=arr[k];
    }
    i++;
    j++;
    mini=val;
    //finding the minimum sum in the array.
    while(j<n){
        val+=(arr[j]-arr[i-1]);
        mini=min(mini,val);
        i++;
        j++;
    }
    return _sum-mini;
}


int main(){
    int arr1[] = { 5, -2, 3 , 1, 2};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int B=3;
    cout<<max_sum(arr1, n, B)<<endl;
    
}
