// String:binary string into substrings with equal number of 0s and 1s
// https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/

#include<iostream>
#include<string>
using namespace std;

int split_binary(string A){
    int count_0=0;
    int count_1=0;
    int n=A.size();
    if(n<2) return -1;
    for(int i=0;i<n;i++){
        if(A[i]=='0') count_0++;
        else count_1++;
    }
    if(count_1!=count_0) return -1;
    int count=0;
    int c0=0,c1=0;
    for(int i=0;i<n;i++){
        if(A[i]=='0') c0++;
        else if(A[i]=='1') c1++;
        if(c0==c1){
            count++;
            c0=0;
            c1=0;
            count_1--;
        }
        if(count_1==0) return -1;
    }
    return  count;
}
//Time: O(n) and Space: O(1)

int main(){
    string v1="0111100010";
    cout<<split_binary(v1)<<endl;
}
