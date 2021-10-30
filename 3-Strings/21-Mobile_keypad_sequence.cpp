// String: Mobile Numeric Keypad Sequence
// https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/

#include<iostream>
#include<string>


using namespace std;

string mobile_sequence(string A[], string B){
    int n=B.size();
    string output="";
    for(int i=0;i<n;i++){
        if(B[i]==' '){
            output+='0';
        }
        else{
            
            int pos=tolower(B[i])-'a';
            output+=A[pos];
        }
    }
    return  output;
}
// Time: O(n)

int main(){
    string A[] = {"2","22","222",
                        "3","33","333",
                        "4","44","444",
                        "5","55","555",
                        "6","66","666",
                        "7","77","777","7777",
                        "8","88","888",
                        "9","99","999","9999"
                       };
    string B="Akshay";
    cout<<mobile_sequence(A, B)<<endl;
    
}
