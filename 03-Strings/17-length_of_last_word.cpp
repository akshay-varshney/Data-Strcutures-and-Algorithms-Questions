// String: Length of Last Word

/*
 Input:
s = "Hello World"
o/p = 5.
 */
#include<iostream>
#include<string>

using namespace std;

int lengthOfLastWord(const string A) {
    int len=0;
    int n=A.size();
    for(int i=n-1;i>=0;i--){
        if(A[i]==' ' && len!=0){
            return len;
        }
        else if(isalpha(A[i])){
            len++;
        }
    }
    return len;
}

//Time: O(n) and Space:O(1)

int main(){
    string A="Hello World  ";
    cout<<lengthOfLastWord(A)<<endl;
    
    
}
