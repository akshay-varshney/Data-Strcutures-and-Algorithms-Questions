// String: Palindrome String
// https://www.interviewbit.com/problems/palindrome-string/

#include<iostream>
#include<string>
using namespace std;

int isPalindrome(string A) {
    int n=A.size();
        string a="";
        string rev="";
        int j=n-1;
        for(int i=0;i<n;i++){
            if(isalpha(A[i]) || isdigit(A[i])){
                a+=tolower(A[i]);
            }
            if(isalpha(A[j]) || isdigit(A[i])){
                rev+=tolower(A[j]);
            }
            j--;
        }
        if(rev==a) return 1;
        return 0;
    }

int main(){
    string v1="A man, a plan, a canal: Panama";
    cout<<isPalindrome(v1)<<endl;
}
