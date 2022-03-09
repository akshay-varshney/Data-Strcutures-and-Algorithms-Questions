// BackTracking: Pallindromic Partitioning

// https://leetcode.com/problems/palindrome-partitioning/

#include<iostream>
#include<vector>
using namespace std;

// function to check palindrome
bool checkPallindrome(string A, int start, int end){
    while(start<=end){
        if(A[start]!=A[end])
            return false;
        start++;
        end--;
    }
    return true;
}

// Now
void printAllPalindrome(string A, vector<vector<string>> &ans, vector<string> &path, int ind){
    // If this is the last partition and it comes out pallindrome then return
    if(ind==A.size()){
        ans.push_back(path);
        return;
    }
    // from index till end of string, make partition and check if that partition makes the string pallindrome
    for(int i=ind; i<A.size(); i++){
        // checking pallindrome from index till i
        if(checkPallindrome(A, ind, i)){
            // if the given string comes out pallindrome then push substring inside vector and keep on adding more partition until reaches last
            path.push_back(A.substr(ind, i-ind+1));
            printAllPalindrome(A, ans, path, i+1);
            path.clear();
        }
    }
}

int main()
{
    vector<vector<string>> S;
    vector<string> path;
    string A="NITIN";
    printAllPalindrome(A, S, path, 0);
    for(int i=0;i<S.size(); i++){
        for(int j=0;j<S[i].size(); j++){
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }
}
