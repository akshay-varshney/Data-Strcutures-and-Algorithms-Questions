// String: Reverse String by characters

/*
 Input:
 A = "abe def"
 Output : "def abe"
 */
#include<iostream>
#include<string>

using namespace std;

string reverse_string(string A){
    int n=A.size();
    string result="";
    int end=n-1;
    string temp="";
    while(end>=0){
        if(A[end]==' ' && A[end+1]!=' '){
            reverse(temp.begin(), temp.end());
            result+=temp;
            result+=' ';
            temp="";
        }
        else if(A[end]==' ' && A[end+1]==' '){
            end--;
            continue;
        }
        else{
            temp+=A[end];
        }
        end--;
    }
    reverse(temp.begin(), temp.end());
    result+=temp;
    return result;
}
//Time: O(n) and Space:O(1)

int main(){
    string A="  abc def";
    cout<<reverse_string(A)<<endl;
    
}
