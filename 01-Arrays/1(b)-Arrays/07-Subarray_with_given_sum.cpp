// Array: Subarray with given sum
// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#
/*
 A[] = {1,2,3,7,5}
 Output: 2 4
 */
#include<iostream>
#include<vector>

using namespace std;

//Time: O(n) and Space:O(1)
vector<int> givensum(vector<int> &A, int req){
    int summed=0;
    int n=A.size();
    vector<int> ans;
    int j=0;
    int i=0;
    while(i<n){
        summed+=A[i];
        if(summed==req){
            ans.push_back(j+1);
            ans.push_back(i+1);
            return ans;
        }
        else if(summed>req){
            summed-=(A[i]+A[j]);
            j++;
        }
        else i++;
    }
    ans.push_back(-1);
    return ans;
}

int main(){
    vector<int> v1={1,2,3,4,5,6,7,8,9,10};
    int value=15;
    vector<int> v2;
    v2=givensum(v1, value);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
}
