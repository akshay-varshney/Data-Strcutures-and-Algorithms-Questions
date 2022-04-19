// Array: Common Elements in three sorted Arrays

// https://practice.geeksforgeeks.org/problems/common-elements1132/1#
/*
 Input:
 n1 = 6; A = {1, 5, 10, 20, 40, 80}
 n2 = 5; B = {6, 7, 20, 80, 100}
 n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
 Output: 20 80

*/
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
vector<int> _common_element(vector<int> A, vector<int> B, vector<int> C, int n1, int n2, int n3){
    if(n1==0 || n2==0 || n3==0) return {};
    int i=0,j=0, k=0;
    vector<int> v;
    while(i<n1 && j<n2 && k<n3){
        if(A[i]==B[j] && B[j]==C[k]){
            // If we have duplicate elements in array then in that case we don't need to push again and again
            int n = v.size();
            if(v.size()>0 && v[n-1]==A[i] ){
                i++;
                j++;
                k++;
                continue;
            }
            v.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        else if(A[i]<B[j]) i++;
        else if(B[j]<C[k]) j++;
        else k++;
    }
    return v;
}

int main(){
    vector<int> v1={1, 5, 10, 20, 40, 80};
    vector<int> v2={6, 7, 20, 80, 100};
    vector<int> v3={3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> v4;
    v4=_common_element(v1, v2, v3, v1.size(), v2.size(), v3.size());
    for(auto it=v4.begin();it!=v4.end();it++){
        cout<<*it<<" ";
    }
  
}
