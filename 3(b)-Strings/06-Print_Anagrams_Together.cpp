
// String: Print Anagrams Together
//https://practice.geeksforgeeks.org/problems/print-anagrams-together/1#
/*
 words[] = {no,on,is}
 Output:
 no on
 is
 
 */
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

bool check_anagram(string A, string B){
    int n=A.size();
    int m=B.size();
    if(m!=n){
        return false;
    }
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
    for(int i=0;i<n;i++){
        unordered_map<char, int>::iterator iter=m1.find(B[i]);
        if(iter==m1.end()){
            return false;
        }
        else{
            iter->second--;
            if(iter->second<0){
                return false;
            }
        }
    }
    return true;
}

vector<vector<string>> generate_anagram(vector<string>& str){
    int n=str.size();
    vector<vector<string>> ans;
    vector<string> v1;
    v1.push_back(str[0]);
    ans.push_back(v1);
    for(int i=1;i<n;i++){
        bool cond=false;
        for(auto it=0;it<ans.size();it++){
            if(check_anagram(str[i], ans[it][0])){
                cond=true;
                ans[it].push_back(str[i]);
                break;
            }
        }
        if(!cond){
            vector<string> temp;
            temp.push_back(str[i]);
            ans.push_back(temp);
        }
    }
    v1={};
    return ans;
}

int main(){
    vector<string> A={"act","god","cat","dog","tac"};
    vector<vector<string>> v2;
    v2=generate_anagram(A);
    for(int i=0;i<v2.size();i++){
        for(int j=0;j<v2[i].size();j++){
            cout<<v2[i][j]<<" ";
        }
        cout<<endl;
    }
}
