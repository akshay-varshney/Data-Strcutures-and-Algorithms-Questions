// String: KMP SubString Search Algorithm
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Program to find if there is siffix which is also a prefix
vector<int>suffix_prefix(string B){
    int n=B.size();
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

// KMP Algorithm
bool substring_search(string A, string B){
    vector<int> temp(B.size());
    temp=suffix_prefix(B);
    int n=A.size();
    int m=B.size();
    int i=0,j=0;
    while(i<n && j<m){
        if(A[i]==B[j]){
            i++;
            j++;
        }
        else{
            if(j!=0) j=temp[j-1];
            else i++;
        }
    }
    if(j==m) return true;
    return false;
}
// Time: O(m+n) and Space: O(m)

int main(){
    string str = "abcxabcdabcdabcy";
    string subString = "abcdabcy";
    cout<<substring_search(str, subString)<<endl;
}
