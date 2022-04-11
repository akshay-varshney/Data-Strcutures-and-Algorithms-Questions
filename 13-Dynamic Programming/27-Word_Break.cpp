
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


//bool MemoizationWordBreak(string A, vector<string>& B, vector<bool> & dp, int position){
//    if(position==A.size())
//        return true;
//    if(dp[position]!=false)
//        return dp[position];
//    for(int i= position; i<=A.size(); i++){
//        string temp = A.substr(position, i);
//        if(dictionarycontains(B, temp) && MemoizationWordBreak(temp, B, dp, i)){
//            dp[position] = true;
//            return true;
//        }
//    }
//    dp[position]= false;
//    return false;
//
//}

// Method 3: By using Top Down
bool wordBreak(string str, vector<string>& B)
{
    int size = str.size();
    if (size == 0)   return true;
 
    // Create the DP table to store results of subproblems. The value wb[i]
    // will be true if str[0..i-1] can be segmented into dictionary words,
    // otherwise false.
    bool wb[size+1];
    memset(wb, 0, sizeof(wb)); // Initialize all values as false.
 
    for (int i=1; i<=size; i++)
    {
        // if wb[i] is false, then check if current prefix can make it true.
        // Current prefix is "str.substr(0, i)"
        if (wb[i] == false && dictionarycontains( B, str.substr(0, i) ))
            wb[i] = true;
 
        // wb[i] is true, then check for all substrings starting from
        // (i+1)th character and store their results.
        if (wb[i] == true)
        {
            // If we reached the last prefix
            if (i == size)
                return true;
 
            for (int j = i+1; j <= size; j++)
            {
                // Update wb[j] if it is false and can be updated
                // Note the parameter passed to dictionaryContains() is
                // substring starting from index 'i' and length 'j-i'
                if (wb[j] == false && dictionarycontains( B, str.substr(i, j-i) ))
                    wb[j] = true;
 
                // If we reached the last character
                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }
    return false;
    
}
int main(){
    string A= "ilike";
    vector<string> B= { "i", "like", "sam",
        "sung", "samsung", "mobile",
        "ice","cream", "icecream",
        "man", "go", "mango"};
    cout<<"Word break:"<<recursiveWordBreak(A, B)<<endl;
    vector<bool> dp(A.size()+1, false);
//    cout<< MemoizationWordBreak(A, B, dp, 0)<<endl;
    cout<<"Memoization Word Break: "<<wordBreak(A, B)<<endl;
}
