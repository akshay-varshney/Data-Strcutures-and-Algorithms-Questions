// Array: Array Subset of another array
// https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1#
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
std::string subset(vector<int> &A, vector<int> B){
    int m=B.size();
    int n=A.size();
    unordered_map<int, int> m1;
    for(int i=0;i<n;i++){
        m1.insert(std::make_pair(A[i], 1));
    }
    for(int i=0;i<m;i++){
        unordered_map<int, int>::iterator iter=m1.find(B[i]);
        if(iter!=m1.end()){
            continue;
        }
        else{
            return "NO";
        }
    }
    return "YES";
}
//Time: O(n+m) and Space:O(n)

int main(){
    vector<int> v1={11, 1, 13, 21, 3, 7};
    vector<int> v2={11, 3, 7, 1};
    cout<<subset(v1, v2)<<endl;
}
