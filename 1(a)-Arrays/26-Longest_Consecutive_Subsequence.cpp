// Array: Longest consecutive subsequence
// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#

/*
 Input:
 N = 7
 a[] = {2,6,1,9,4,5,3}
 Output:
 6
 */

#include<iostream>
#include<vector>
#include<set>

using namespace std;
// Using Kadens Algorithm
int longest_consecutive(vector<int> &arr){
    int n=arr.size();
    if(n<=1) return 1;
    set<int> s1;
    for(int i=0;i<n;i++){
        s1.insert(arr[i]);
    }
    int count=1;
    int longest_count=1;
    set<int>::iterator iter1=s1.begin();
    auto it=iter1;
    it++;
    for(auto i=it;i!=s1.end();i++){
        if(*i-*iter1==1){
            count++;
        }
        else{
            count=1;
        }
        iter1=i;
        longest_count=max(longest_count,count);
    }
    return longest_count;
}
// Time:O(n) and Space:O(n)

int main(){
    vector<int> v1={2,6,1,9,4,5,3};
    cout<<longest_consecutive(v1)<<endl;
}
