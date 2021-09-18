//Array: Duplicate in an array
// https://leetcode.com/problems/find-the-duplicate-number/solution/

#include<iostream>
#include<unordered_map>

using namespace std;

// Method 1: If the array contains any element then use this one
// Time: O(n) and Space: O(n)
int duplicate_num(int arr[], int n){
    unordered_map<int,bool> m1;
    for(int i=0;i<n;i++){
        if(m1.count(arr[i])){
            return arr[i];
           
        }
        else{
            m1.insert({arr[i],true});
        }
    }
    return -1;
}

// Method: 2 If array contains values in range of n+1
// Time: O(n) and space: O(1)
int negative_duplicate(int arr[], int n){
    for(int i=0;i<n;i++){
        int val=abs(arr[i]);
        if(arr[val]<0){
            return abs(arr[val]);
        }
        else{
            arr[val]*=-1;
        }
    }
    return -1;
}
// Method 2 Swap with 0 : If array contains values in range of n+1
// Time: O(n) and space: O(1)
int findDuplicate(int arr[],int n) {
        while (arr[0] != arr[arr[0]])
            swap(arr[0], arr[arr[0]]);
        return arr[0];
    }

int main(){
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int arr2[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    cout<<duplicate_num(arr, n)<<endl;
    cout<<negative_duplicate(arr, n)<<endl;
    cout<<findDuplicate(arr2,n2)<<endl;
}


