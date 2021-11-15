// Searching & Sorting: Zero Sum Subarray
//https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int zero_sum_subarray(vector<int> &A){
    int n=A.size();
    int sumeed=0;
    int count=0;
    unordered_map<int, int> m1;
    for(int i=0;i<n;i++){
        sumeed+=A[i];
        if(sumeed==0){
            count++;
        }
        unordered_map<int, int>::iterator iter=m1.find(sumeed);
        if(iter!=m1.end()){
            count+=(iter->second);
            iter->second++;
        }
        else{
            m1.insert(std::make_pair(sumeed, 1));
        }
    }
    return count;
}
//Time: O(n) and Space: O(n)


int main(){
    vector<int> v1= {0,0,5,5,0,0};
    cout<<zero_sum_subarray(v1)<<endl;

}
