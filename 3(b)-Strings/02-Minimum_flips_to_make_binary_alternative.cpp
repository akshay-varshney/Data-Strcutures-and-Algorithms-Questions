// String: Number of flips to make binary string alternate
//https://www.geeksforgeeks.org/number-flips-make-binary-string-alternate/

/*
 Input : str = “0001010111”
 Output : 2
 */
#include<iostream>
#include<string>

using namespace std;

// Checking the indexes of the odd position and even position
// Example: 0 1 0 either even index can have all 0 and odd index can have all 1 and vice versa.
//seq 1: 0 1 0 ( even: 0 and odd :1 other than this we'll increment the count)
//seq 2: 1 0 1 ( even: 1 and odd :0 other than this we'll increment the count)
int minimum_flips(string A){
    int n=A.size();
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
        if(i%2!=0 && A[i]=='0') count1++;
        if(i%2==0 && A[i]=='1') count1++;
        if(i%2!=0 && A[i]=='1') count2++;
        if(i%2==0 && A[i]=='0') count2++;
    }
    return min(count1,count2);
}
// Time: O(n) and Space: O(1)

int main(){
    string A="1111110000000000000";
    cout<<minimum_flips(A)<<endl;
   
}
