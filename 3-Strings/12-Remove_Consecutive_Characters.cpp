// String: Remove Consecutive Characters
// https://www.interviewbit.com/problems/remove-consecutive-characters/

#include<iostream>
#include<string>
using namespace std;

string remove_consecutive(string A, int B){
    int n=A.size();
    if (B>n) return "";
    string ans="";
    int i=0;
    while(i<n){
        int s=i;
        bool flag=false;
        for(int j=s;j<s+B-1;j++){
            if(A[j]==A[j+1]) flag=true;
            else{
                ans+=A[j];
                i++;
                flag=false;
                break;
            }
        }
        if(flag==true) i+=B;
    }
    return ans;
}
// Time: O(n) and Space: O(1)

int main(){
    string v1="aaagccc";
    cout<<remove_consecutive(v1, 3)<<endl;
}
