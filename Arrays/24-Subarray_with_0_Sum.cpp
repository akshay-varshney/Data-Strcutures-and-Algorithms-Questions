// Array: Subarray with 0 sum

// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#
/*

 Input:  arr[] = {4 2 -3 1 6}
 output: True
*/

#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

bool subarray(vector<int> &A){
    unordered_map<int, int> m1;
    int summed=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        summed+=A[i];
        unordered_map<int, int>::iterator iter=m1.find(summed);
        if (iter != m1.end() || summed==0){
            return true;
        }
        else{
            m1.insert(std::make_pair(summed, 1));
        }
    }
    return false;
}

// Time Complexity: O(n) and Space: O(n)
int main(){
    vector<int> v1={-21, 21, 30, -7, 45, 49, -26, 38, 4, 36, 19, -18, 19, -40, 23, -20, -17, 13};
    cout<<subarray(v1)<<endl;
}
