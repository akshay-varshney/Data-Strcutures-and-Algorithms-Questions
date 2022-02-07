// String: Convert Roman to Integer
//https://www.interviewbit.com/problems/roman-to-integer/

#include<iostream>
#include<string>
#include<unordered_map>


using namespace std;

int roman_to_integer(string A){
    unordered_map<char,int>m1;
    m1.insert(std::make_pair('I',1));
    m1.insert(std::make_pair('V',5));
    m1.insert(std::make_pair('X',10));
    m1.insert(std::make_pair('L',50));
    m1.insert(std::make_pair('C',100));
    m1.insert(std::make_pair('D',500));
    m1.insert(std::make_pair('M',1000));
    int n=A.size();
    int result=m1[A[n-1]];
    for(int i=n-2;i>=0;i--){
        if(m1[A[i]]<m1[A[i+1]]){
            result-=m1[A[i]];
        }
        else{
            result+=m1[A[i]];
        }
    }
    return result;
}

int main(){
    string A="MMMCXIV";
    cout<<roman_to_integer(A)<<endl;
}
