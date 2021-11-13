// Searching & Sorting: Majority Element
//https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#

#include<iostream>
#include<vector>
using namespace std;

// Taking two variable and checking the occurence of that element in entire array and keep on updating the majority element if the value of the count becomes 0
int majority_element(vector<int> &A){
    int n=A.size();
    int count=1;
    int majority=A[0];
    for(int i=1;i<n;i++){
        if(A[i]==majority){
            count++;
        }
        else{
            count--;
            if(count==0){
                majority=A[i];
                count=1;
            }
        }
    }
    count=0;
    // checking the actual count of find majority element from above loop
    for(int i=0;i<n;i++){
        if(A[i]==majority){
            count++;
        }
    }
    if(count>n/2){
        return majority;
    }
    // if count is less than n/2 return -1
    return -1;
}
// Time: O(n) and Space: O(1)


int main(){
    vector<int> v1= {3, 1, 3, 3, 2};
    cout<<majority_element(v1)<<endl;
}
