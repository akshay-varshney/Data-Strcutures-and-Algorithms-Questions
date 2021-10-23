// String: Print all subsequences of a string
// https://www.geeksforgeeks.org/print-subsequences-string/
/*
 S = "aaaabbaa"
 Output: aabbaa
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print_subsequence(string Inp, string Out){
    if(Inp.size()==0){
        std::cout<<Out<<std::endl;
        return ;
    }
    print_subsequence(Inp.substr(1), Out);
    print_subsequence(Inp.substr(1), Out+Inp[0]);
}


int main(){
    string v1="";
    string v2="abs";
    print_subsequence(v2, v1);
}
