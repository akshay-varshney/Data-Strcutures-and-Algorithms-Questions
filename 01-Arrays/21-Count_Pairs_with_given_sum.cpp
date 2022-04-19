// Array: Count pairs with given sum

// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#
/*
 Input:
 N = 4, K = 6
 arr[] = {1, 5, 7, 1}
 Output: 2
*/

#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;
// Using Unordered map to store the count of the variable.
int getpair_count(vector<int> A,int n, int x){
    unordered_map<int, int> m1;
    for(int i=0;i<n;i++){
        std::unordered_map<int, int>::iterator it = m1.find(A[i]);
           if (it != m1.end()) {
               it->second++;
           }
           else {
               m1.insert(std::make_pair(A[i], 1));
           }
    }
    int count=0;
    bool flag=false;
    for(int i=0;i<n;i++){
        flag=false;
        std::unordered_map<int, int>::iterator it = m1.find(x-A[i]);
        
           if (it != m1.end()) {
               // If element is pointing to itself then decremenet the count by 1, as element cannot make pair with itself.
               if(A[i]==it->first){
                   it->second--;
                   flag=true;
               }
               count+=it->second;
           }
        if(flag==true){
            it->second++;
        }
    }
    return count/2;
}
// Time : O(n) and Space: O(n)

int main(){
    vector<int> v1={1,1, 1, 1};
    vector<int> v2;
    cout<<getpair_count(v1, v1.size(), 2);
}
