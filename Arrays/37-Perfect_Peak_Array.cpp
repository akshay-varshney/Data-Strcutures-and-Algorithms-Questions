// Array: Perfect Peak of Array
// https://www.interviewbit.com/problems/perfect-peak-of-array/
/*
 Input>A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
 O/p: 1
 */
#include<iostream>
#include<vector>

using namespace std;

// Creating a Prefix array of maximum elements till now
// Creating a suffix array of minimum element till now
bool perfect_peak(vector<int> &A){
    int n=A.size();
    vector<int> Maxi(n);
    vector<int> Mini(n);
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        maxi=max(maxi,A[i]);
        Maxi[i]=maxi;
    }
    for(int i=n-1;i>=0;i--){
        mini=min(mini,A[i]);
        Mini[i]=mini;
    }
    for(int i=1;i<=n-2;i++){
        if(Maxi[i-1]<A[i] && A[i]<Mini[i+1]) return true;
        else{
            cout<<"NO "<<A[i]<<endl;
        }
    }
    return false;
}
// Time: O(n) and Space: O(n)

int main(){
    vector<int> v1={5,4,3,1,6,1,7,10};
    cout<<perfect_peak(v1)<<endl;
}
