// String: Edit Distance
//Insert a character at any position of the string.
//Remove any character from the string.
//Replace any character from the string with any other character.

/*
 Input:
 s = "leak", t = "leek"
 Output: 1
 */
#include<iostream>
#include<string>

using namespace std;

int edit_distance(string A, string B){
    int n=A.size();
    int m=B.size();
    int count=0;
    if(n==m){
        int i=0;
        while(i<n){
            if(A[i]==B[i]) continue;
            else count++;
            i++;
        }
    }
    else{
        int equals=0;
        if(m>n){
            swap(A,B);
            swap(n,m);
        }
        int i=0; int j=0;
        while(i<n && j<m){
            if(A[i]==B[j]){
                i++;
                j++;
                equals++;
            }
            else{
                i++;
            }
        }
        count=n-equals;
    }
    return count;
}
//Time: O(n) and Space:O(1)

int main(){
    string A="deep";
    string B="deeper";
    cout<<edit_distance(A,B)<<endl;
}
