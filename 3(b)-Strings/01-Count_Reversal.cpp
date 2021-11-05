// String: Count the Reversals
//https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/

/*
 Input:
 S = "}{{}}{{{"
 Output: 3
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int count_reversal(string A){
    int n=A.size();
        if(n%2!=0){
            return -1;
        }
        vector<char> temp;
        for(int i=0;i<n;i++){
            if(temp.size()>0){
                char first=temp.back();
                if(A[i]=='}' && first=='{'){
                    temp.pop_back();
                }
                else{
                    temp.push_back(A[i]);
                }
            }
            else{
                temp.push_back(A[i]);
            }
        }
        int end=temp.size();
        int mid=end/2;
        int count=0;
        int i=0;
        while(i<end && temp.back()=='{'){
            temp.pop_back();
            count++;
        }
        return end/2+(count%2); // forward/2 +backward/2
    
}
//time: O(n) and Space: O(n)


int main(){
    string A="}{}{}{}}}{{{{{}{}{}}{{}{}{}}{{}}{{";
    cout<<count_reversal(A)<<endl;
}
