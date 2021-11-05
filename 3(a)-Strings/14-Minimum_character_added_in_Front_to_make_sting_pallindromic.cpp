// String: Minimum Characters required to make a String Palindromic
// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
/*
 Input:
     A = "AACECAAAA"
 Output :2
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// LPS Array: Longest Suffix which is also prefix
vector<int>suffix_prefix(string B, int n){
    vector<int> ans(n);
    int val=0;
    int i=1;
    while(i<n){
        if(B[i]==B[val]){
            ans[i]=val+1;
            i++;
            val++;
        }
        else{
            if(val==0){
                ans[i]=0;
                i++;
            }
            else val=ans[val-1];
        }
    }
    return ans;
}
// Time: O(n) and space:O(n)


int mini(string A){
    int n=A.size();
    string a=A;
    reverse(a.begin(), a.end());
    string str=A+"@"+a;
    vector<int>v2=suffix_prefix(str,str.size());
    cout<<v2.back()<<endl;
    return n-v2.back();
}

int main(){
    string A="aaaa";
    cout<<mini(A)<<endl;
}
