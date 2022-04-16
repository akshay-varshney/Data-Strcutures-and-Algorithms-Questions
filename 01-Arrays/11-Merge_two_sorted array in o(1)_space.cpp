// Array: Merge two sorted Arrays
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#

#include<iostream>
#include<vector>

using namespace std;
// Method 1: Time taken woyld be more as we are using some sorting in arr2
int merge(vector<int> arr1, vector<int> arr2, int n, int m){
    int start1=0,start2=0;
    if (n<=0){
        for(int i=0;i<m;i++){
            cout<<arr2[i]<<" ";
        }
    }
    if (m<=0){
        for(int i=0;i<n;i++){
            cout<<arr1[i]<<" ";
        }
    }
    
    while(start1<n && start2<m){
        if(arr1[start1]>arr2[start2]){
            swap(arr1[start1],arr2[start2]);
            if(arr2[start2]>arr2[start2+1]){ // sort arr2
                int j=0;
                while(arr2[start2+j]>arr2[start2+j+1]){
                    swap(arr2[start2+j],arr2[start2+j+1]);
                    j++;
                }
            }
        }
        else if (arr1[start1]<arr2[start2]){
            start1++;
        }
        else{
            start1++;
            
        }
    }
    return 0;
}

// Method 2: Traverssing from back in which we placing the greater element first and then setting up smaller one
// Space: O(1) amd Time O(m*n)
void merge_2(vector<int>& ar1, vector<int>& ar2, int m, int n){
   
    for (int i=n-1; i>=0; i--)
        {
            
            int j, last = ar1[m-1];
            j=m-2;
            bool flag = false;
            while(j >= 0 && ar1[j] > ar2[i])
            {
                ar1[j+1] = ar1[j];
                j--;
                flag = true;
            }
            // If there was a greater element in a1 as compared to a2
            if (flag || last > ar2[i])
            {
                ar1[j+1] = ar2[i];
                ar2[i] = last;
            }
        }
}
void pr(vector<int> &arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0,2, 6, 8, 9};
    int n= arr1.size();
    int m= arr2.size();
//    merge(arr1,arr2,n,m); // Method-1
    merge_2(arr1, arr2, n, m); // Method -2
    pr(arr1, n);
    pr(arr2,m);
}
