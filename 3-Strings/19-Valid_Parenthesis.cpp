// String: Parenthesis Checker
// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#

/*
 Input: {([])}
 Output:
 true
 */
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool balanced_parenthesis(string A){
    int n=A.size();
    std::vector<char> para1;
    for(int i=0;i<n;i++){
        if(A[i]=='{' || A[i]=='(' || A[i]=='['){
            para1.push_back(A[i]);
        }
        else if(A[i]==']' || A[i]==')' || A[i]=='}'){
            if(para1.size()==0){
                return 0;
            }
            else if(A[i]==']' && para1.back()=='['){
                para1.pop_back();
            }
            else if(A[i]==')' && para1.back()=='('){
                para1.pop_back();
            }
            else if(A[i]=='}' && para1.back()=='{'){
                para1.pop_back();
            }
            else{
                return 0;
            }
        }
    }
    if(para1.size()!=0) return 0;
    return 1;
}
// Time: O(n) and space: O(n)

int main(){
    string A="{}{(}))}";
    cout<<balanced_parenthesis(A)<<endl;
}
