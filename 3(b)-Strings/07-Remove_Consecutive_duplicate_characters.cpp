
// String: Remove Consecutive Characters
//https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1
/*
 S = aabb
 Output:  ab
 */
#include<iostream>
#include<string>
using namespace std;

string remove_dupliate(string A){
    int n=A.size();
    string ans="";
    for(int i=0;i<n-1;i++){
        if(A[i]==A[i+1]){
            continue;
        }
        else{
            ans+=A[i];
        }
    }
    ans+=A[n-1];
    return ans;
}
//Time: O(n) and Space: O(1)

// Methgod-2 by using recurssion
string removeConsecutive(string s)
   {
       int n = s.size();
       if(n == 0 || n == 1){
           return s;
       }
       if(s[0] == s[1]){
           int index = 0;
           while(s[index] == s[0] && index < n){
               index++;
           }
           return s[0] + removeConsecutive(s.substr(index));
       }
       return s[0] + removeConsecutive(s.substr(1));
   }

int main(){
    string A="aabaa";
    cout<<remove_dupliate(A)<<endl;
    cout<<removeConsecutive(A)<<endl;
}
