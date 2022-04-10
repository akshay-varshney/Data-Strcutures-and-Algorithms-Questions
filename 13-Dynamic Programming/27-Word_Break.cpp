
// Dynamic Programming: Word break
//https://practice.geeksforgeeks.org/problems/word-break1352/1


#include<iostream>
#include<vector>
using namespace std;

bool dictionarycontains(vector<string>& B, string word){
    for(int i=0; i<B.size(); i++){
        if(B[i]==word)
            return true;
    }
    return false;
}

// Method 1: By using Recurssion
bool recursiveWordBreak(string A, vector<string>& B){
    int n=A.size();
    if(n==0)
        return true;
    for(int i=0; i<=n; i++){
        if(dictionarycontains(B, A.substr(0,i)) && recursiveWordBreak(A.substr(i, n-i), B))
           return true;
    }
    return false;
}


int main(){
    string A= "ilike";
    vector<string> B= { "i", "like", "sam",
        "sung", "samsung", "mobile",
        "ice","cream", "icecream",
        "man", "go", "mango"};
    cout<<recursiveWordBreak(A, B)<<endl;
}
