// String: Longest Common Prefix
// https://www.interviewbit.com/problems/longest-common-prefix/
/*
 A = ["abcdefgh", "aefghijk", "abcefgh"]
 O/p: a
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string prefix_check(string A, string B){
    string result="";
    int i=0,j=0;
    int n=A.size();
    int m=B.size();
    while(i<n && j<m){
        if(A[i]!=B[j]){
            break;
        }
        result+=A[i];
        i++;
        j++;
    }
    return result;
}

string longest_common(vector<string> A){
    int n=A.size();
    string B=A[0];
    for(int i=1;i<n;i++){
        B=prefix_check(A[i], B);
    }
    return B;
}

int main(){
    vector<string> A = {"abab", "ab", "abcd"};
    cout<<longest_common(A)<<endl;
}
