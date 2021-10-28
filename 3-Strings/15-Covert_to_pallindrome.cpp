// String: Convert to pallindrome
// https://www.interviewbit.com/problems/convert-to-palindrome/
/*
 Input:
 A = "abecbea"
 Output : 0
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int convert_palindrome(string A){
    int start=0;
    int end=A.size()-1;
    int mid=(start+end)/2;
    int count=1;
    while(start<=end && count>=0){
        if(A[start]==A[end]){
            if(start==end){
                break;
            }
            start++;
            end--;
        }
        else{
            start++;
            count--;
        }
    }
    if(start==end && count>=0) return 1;
    return 0;
}
//Time: O(n) and Space:O(1)

int main(){
    string A="gdd";
    cout<<convert_palindrome(A)<<endl;
}
