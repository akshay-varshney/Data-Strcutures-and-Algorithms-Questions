// Array: Repeat and Missing Number Array
// https://www.interviewbit.com/problems/repeat-and-missing-number-array/
/*
 Input:[3 1 2 5 3]

 Output:[3, 4] 
 */
#include<iostream>
#include<vector>

using namespace std;
vector<int> first_poitive(vector<int> &A){
    int n=A.size();
    int start=0;
    vector<int> ans={};
    while(start<n){
        if(A[start]>0 && A[start]<=n){
            if(A[start]==A[A[start]-1]){
                start++;
            }
            else swap(A[start],A[A[start]-1]);
        }
        else start++;
    }
        for(int i=0;i<n;i++){
            if(A[i]==i+1) continue;
            else{
                ans.push_back(i+1);
                ans.push_back(A[i]);
            }        }
    return ans;
}

int main(){
    vector<int> v1={3, 1, 2, 5, 3};
    vector<int> v2;
    v2=first_poitive(v1);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<endl;
    }
}
