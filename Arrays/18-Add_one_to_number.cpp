// Array: Add one to the number.
// https://www.interviewbit.com/problems/add-one-to-number/

// Input:  A = [1,2,3]
// O/p = [1,2,4]

#include<vector>
#include<iostream>

using namespace std;

// Method
vector<int> plusOne(vector<int> &A) {
    // Eliminate 0 from start if present any
    reverse(A.begin(), A.end());
    for(int i=A.size()-1;i>=0;i--){
        if(A[i]==0) A.pop_back();
        else break;
    }
    reverse(A.begin(), A.end());
    //count all the 9's in the array
    int n=A.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(A[i]==9){
            count++;
        }
    }
    vector<int> v1;
    // If count is same as size of array then all values should be 0 except first one.
    if(count==n){
        v1.push_back(1);
        for(int i=0;i<n;i++) v1.push_back(0);
        return v1;
    }
    else if(A[n-1]==9){
        for(int i=n-1;i>=0;i--){
            if(A[i]==9) A[i]=0;
            else{
                A[i]++;
                break;
            }
        }
    }
    else A[n-1]++;
    return A;
}
// Time Complexity: O(n) and Space Complexity O(n)
int main(){
    vector<int> v1={ 3, 0, 6, 4, 0};
    vector<int> v2;
    v2=plusOne(v1);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
}
