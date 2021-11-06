// String: Smallest window that contains all characters of string itself
//https://www.geeksforgeeks.org/smallest-window-contains-characters-string/

/*
 Input: aabcbcdbca
 Output: dbca
 */
#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;
string smallest_substring(string A){
    unordered_set<char> s1;
    int n=A.size();
    for(int i=0;i<n;i++){
        s1.insert(A[i]);
    }
    int strLen=s1.size();
    int i=0;
    int s=0;
    int e=n;
    while((i+strLen)<=n){
        int start=i;
        int end=i+1;
        unordered_set<char> s2;
        s2.insert(A[start]);
        while(end<n){
            
            if(A[start]==A[end] && end-start==1){
                if(s2.size()==strLen){
                    return A.substr(start,1);
                }
                start++;
                end++;
                i++;
            }
            else{
                s2.insert(A[end]);
                if(s2.size()==strLen){
                    if((e-s)>(end-start)){
                        s=start;
                        e=end;
                    }
                    break;
                }
                end++;
            }
        }
        i=start+1;
    }
    return A.substr(s,e-s+1);
}
// Time: O(n2) and space: O(n)

int main(){
    string A="CCABBAbBCABB";
    cout<<smallest_substring(A)<<endl;
  
}
