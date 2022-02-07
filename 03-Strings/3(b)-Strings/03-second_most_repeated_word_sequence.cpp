// String: Second most repeated word in a sequence
//https://www.geeksforgeeks.org/second-repeated-word-sequence/

/*
 Input : {"aaa", "bbb", "ccc", "bbb",
          "aaa", "aaa"}
 Output : bbb
 */
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

string second_consecutive(string A[], int n){
    unordered_map<string, int> m1;
    for(int i=0;i<n;i++){
        unordered_map<string, int>::iterator iter=m1.find(A[i]);
        if(iter!=m1.end()){
            iter->second++;
        }
        else{
            m1.insert(std::make_pair(A[i], 1));
        }
    }
    int first=INT_MIN;
    int second=INT_MIN;
    string find="";
    string a="";
    for(auto it=m1.begin();it!=m1.end();it++){
        bool flag=false;
        if(first<it->second){
            if(second<first){
                second=first;
                find=a;
            }
            first=it->second;
            a=it->first;
        }
        else if (it->second > second && it->second != first){
        second = it->second;
        find=it->first;
        }
    }
    return find;
}


int main(){
    string arr[] = {"geek", "for", "geek", "for", "geek", "aaa"};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<second_consecutive(arr,n)<<endl;
}
