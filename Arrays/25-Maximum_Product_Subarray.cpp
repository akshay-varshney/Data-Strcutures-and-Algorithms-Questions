// Array: Maximum Product of subarray
// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/


#include<iostream>
#include<vector>

using namespace std;
// Using Kadens Algorithm
int max_product(vector<int> &arr){
    int n=arr.size();
    int mini= arr[0];
        int maxi = arr[0];
        int prod = arr[0];
        for (int i = 1; i < n; i++) {
            //if value of array is -ve that means that maxi and mini value interchanged
            if (arr[i] < 0)
                swap(maxi, mini);
            // These two keep track of maximum and minimum value in array all the time
            maxi = max(arr[i], maxi * arr[i]);
            mini= min(arr[i], mini* arr[i]);
     
            prod = max(prod, maxi);
        }
    return prod;
}


int main(){
    vector<int> v1={-2,4,6,2,4,-1,-9};
    cout<<max_product(v1)<<endl;
}
