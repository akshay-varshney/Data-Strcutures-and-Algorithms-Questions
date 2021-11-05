// String: Print all Duplicate in string

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

void duplicate_string(std::string A){
    int n=A.size();
    unordered_map<char, int> m1;
    for(int i=0;i<n;i++){
        unordered_map<char, int>::iterator iter=m1.find(A[i]);
        if(iter!=m1.end()){
            iter->second++;
        }
        else{
            m1.insert(std::make_pair(A[i], 1));
        }
    }
    for(auto it=m1.begin();it!=m1.end();it++){
        if(it->second>1){
            std::cout<<it->first<<" ";
        }
    }
}
// Time: O(n) and space:O(n)

int main(){
    string val="CABAC";
    duplicate_string(val);
}
