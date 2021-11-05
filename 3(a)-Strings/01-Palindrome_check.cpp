// String: Check whether a string is a palindrome or not

#include<iostream>

using namespace std;

int palindrome(std::string original){
    int n=original.size();
    int start=0;
    int end=n-1;
    while(start<=end){
        if(original[start]!=original[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main(){
    string val="CABAC";
    cout<<palindrome(val)<<endl;
    
}
