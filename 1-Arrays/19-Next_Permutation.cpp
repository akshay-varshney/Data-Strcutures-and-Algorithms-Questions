// Array: Find the next permutation
// https://leetcode.com/problems/next-permutation/submissions/

// Input: nums = [3,2,1]
//Output: [1,2,3]

#include<vector>
#include<iostream>

using namespace std;
// 3 steps: 1. Find the first point which is having decreasing value in a subarray.
//2. swap this with the value greater than element in subarray.
//3. sort the subarray
vector<int> next_permutation(vector<int> &v1){
    int n=v1.size();
    if(n<=1) return v1;
    int val=n-2;
    while(val>=0 && v1[val]>= v1[val+1]){
        val--;
    }
    if (val<0){
        sort(v1.begin(),v1.end());
    return  v1;
    }
    for(int i=n-1;i>val;i--){
        if(v1[i]>v1[val]){
            swap(v1[i],v1[val]);
            break;
        }
    }
    sort(v1.begin()+val+1,v1.end());
    return v1;
}
// time complexity: O(nlogn)
//space O(1)

int main(){
    vector<int> v1={1,2,3,2,1};
    vector<int> v2;
    v2=next_permutation(v1);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }

}
