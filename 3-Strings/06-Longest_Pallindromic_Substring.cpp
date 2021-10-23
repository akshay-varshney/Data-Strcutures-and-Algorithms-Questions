// String: Longest Palindromic Substring
// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1#
/*
 S = "aaaabbaa"
 Output: aabbaa
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Taking two pointers if both are equal then we'll be iterating it towards left and right part of the array.
string longest_palindrome(string A){
    int n=A.size();
    if(n<=1) return  A;
    int start=0;
    int end=0;
    int max_len=1;
    // If pallindrome of odd length
    for(int i=0;i<n-1;i++){
        int low=i;
        int high=i;
        while(low>=0 && high<n){
            if(A[low]==A[high]){
                low--;
                high++;
            }
            else break;
        }
        int value=high-low-1;
        if(value>max_len)
        {
            max_len=value;
            start=low+1;
            end=high-1;
        }
    }
    // If pallindrome of even length
    for(int i=0;i<n-1;i++){
        int low=i;
        int high=i+1;
        while(low>=0 && high<n){
            if(A[low]==A[high]){
                low--;
                high++;
            }
            else break;
        }
        int value=high-low-1;
        if(value>max_len){
            max_len=value;
            start=low+1;
            end=high-1;
        }
    }
    return A.substr(start,max_len);
}
// Time: O(n^2) and Space: O(1)

int main(){
    string v1="bbc";
    cout<<longest_palindrome(v1)<<endl;
}
