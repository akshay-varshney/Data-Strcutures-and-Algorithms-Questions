// String: Compare Version Number
//https://www.interviewbit.com/problems/compare-version-numbers/

#include<iostream>
#include<string>


using namespace std;

int comparision(string A, string B){
    int i =  0 , j =  0 , m = A.length() , n = B.length();
        int val1, val2;
        while(i < m || j < n){
            val1 = val2 = 0;
            while(i < m && isdigit(A[i])){
                val1 = val1*10+(A[i]-'0');
                i++;
            }
            while(j < n && isdigit(B[j])){
                val2 = val2*10+(B[j]-'0');
                j++;
            }
            if(j < n && B[j] == '.') ++j;
            if(i < m && A[i] == '.') ++i;
            if(val1 > val2) return 1;
            else if(val1 < val2) return -1;
        }
        return 0;
    
}

int main(){
    string A="1.13";
    string B="1.13.4";
    cout<<comparision(A, B)<<endl;
}
