// String: Add Binary Strings
//https://www.interviewbit.com/problems/add-binary-strings/

#include<iostream>
#include<string>
using namespace std;

string add_binary(string A, string B){
    if(B.size()>A.size()){
        swap(A,B);
    }
    int n=A.size();
    int m=B.size();
    int i=n-1;
    int j=m-1;
    int carry=0;
    string ans="";
    while(i>=0 && j>=0 ){
        int val=(A[i]-'0')+(B[j]-'0');
        val+=carry;
        int next=val;
        carry=next/2;
        val=val%2;
        ans+=to_string(val);
        i--;
        j--;
    }
    while(i>=0){
        int val=(A[i]-'0');
        val+=carry;
        int next=val;
        carry=next/2;
        val=val%2;
        ans+=to_string(val);
        i--;
    }
    if(carry!=0){
        ans+='1';
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
//Time: O(m+n) space: O(1)


int main(){
    string A="110";
    string B="111";
    cout<<add_binary(A, B)<<endl;
}
