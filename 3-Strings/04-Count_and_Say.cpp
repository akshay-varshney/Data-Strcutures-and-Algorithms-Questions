// String: Count and say
//https://leetcode.com/problems/count-and-say/

/*
 Input 4
 1
 11
 21
 o/p: 1211
 */
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string count_say(int n){
    string x="1";
    if(n<1) return "";
    for(int i=1;i<n;i++){
        string y="";
        int count=1;
        for(int j=0;j<x.size();j++){
            if(x[j]==x[j+1]) count++;
            else{
                y+=to_string(count);
                y+=x[j];
                count=1;
            }
        }
        x=y;
    }
    return x;
}

int main(){
    cout<<count_say(5)<<endl;
}
