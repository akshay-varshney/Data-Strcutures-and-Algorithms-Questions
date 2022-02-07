// String: Check if two strings are rotation of each other
//https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

// Time:O(n) and space: O(1)
bool rotation(string A, string B){
    int n=A.size();
    int m=B.size();
    if(m!=n) return false;
    string temp=A+B;
    int x=n-1;
    string value=A;
    while(x<2*n){
        if(value==B){
            return true;
        }
        x++;
        value=value.substr(1);
        value+=temp[x];
    }
    return false;
}

int main(){
    string val="AACD";
    string val2 = "ACDA";
    cout<<rotation(val, val2);
}
