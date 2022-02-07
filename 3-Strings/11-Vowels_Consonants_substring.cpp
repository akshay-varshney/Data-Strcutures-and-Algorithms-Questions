// String: Vowel and Consonant Substrings
// https://www.interviewbit.com/problems/vowel-and-consonant-substrings/

#include<iostream>
#include<string>
using namespace std;

int vowel_consonant(string A){
    long long vowel=0;
    long long consonant=0;
    long long mode=1000000007;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(A[i]=='a' || A[i]=='e' || A[i]=='i'|| A[i]=='o' || A[i]=='u' || A[i]=='A' || A[i]=='E'|| A[i]=='I' || A[i]=='O' || A[i]=='U'){
            vowel++;
        }
        else consonant++;
    }
    if(vowel==0 || consonant==0) return 0;
    long long substring=0;
    for(int i=0;i<n-1;i++){
        if(A[i]=='a' || A[i]=='e' || A[i]=='i'|| A[i]=='o' || A[i]=='u' || A[i]=='A' || A[i]=='E'|| A[i]=='I' || A[i]=='O' || A[i]=='U'){
            substring+=consonant;
            substring=substring%mode;
            vowel--;
        }
        else{
            substring+=vowel;
            substring=substring%mode;
            consonant--;
        }
    }
    return substring;
}

int main(){
    string v1="adceba";
    cout<<vowel_consonant(v1)<<endl;
}
