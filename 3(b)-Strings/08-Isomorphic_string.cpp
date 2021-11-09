
// String: Isomorphic Strings
//https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#
/*
 str1 = aab
 str2 = xyz
 Output: 0
 */
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool areIsomorphic(string str1, string str2){
    unordered_map<char , int> m1;
    int n=str1.size();
    int m=str2.size();
    if(m!=n) return false;
    for(int i=0;i<n;i++){
        m1[str1[i]]++;
    }
    unordered_map<char, int> m2;
    for(int i=0;i<m;i++){
        unordered_map<char, int>::iterator iter=m1.find(str2[i]);
        if(iter!=m1.end()){
            return false;
        }
        m2[str2[i]]++;
    }
    if(m1.size()!=m2.size()) return false;
    return true;
        
}
int main(){
    string A="aab";
    string B="xxy";
    cout<<areIsomorphic(A, B)<<endl;
    
}
