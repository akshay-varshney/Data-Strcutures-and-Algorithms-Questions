// String:Rabin Carp Algorithm
// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

#include<iostream>
#include<string>


using namespace std;

int pattern_matching(string A, string B, int primes){
    int ch=256;
    int n=A.size();
    int m=B.size();
    int pat=0;
    int text=0;
    int hash=1;
    // calculating the power of n-1 to subtract the first value from hash if not matched
    for(int i=0;i<m-1;i++){
        hash=(hash*ch)%primes;
    }
    // hash values of pattern and text
    for(int i=0;i<m;i++){
        pat=(pat*ch+B[i])%primes;
        text=(text*ch+A[i])%primes;
    }
    for(int i=0;i<=n-m;i++){
        // if both hash values are same
        if(pat==text){
            bool flag=true;
            for(int j=0;j<m;j++){
                if(A[i+j]!=B[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        // if both hash values comes different then remove the first value and add the next value in the hash.
        // first we need to left shift the current hash value to left shift current hash value we need to multiply by base number
        // then finally after left shifting just add the current number to it.
        if(i<n-m){
            text=(ch*(text-A[i]*hash)+A[i+m])%primes;
            if(text<0)
                text+=primes;
        }
    }
    return -1;
}

int main(){
    string A="Akshay";
    string B="ha";
    int primes=101;
    cout<<pattern_matching(A, B, primes)<<endl;
}
