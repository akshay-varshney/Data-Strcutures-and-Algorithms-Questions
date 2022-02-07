// Searching: First and last occurrences of x
//https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#
#include<iostream>
#include<vector>

using namespace std;

vector<int> first_last_occurence(vector<int> A, int x){
    int n=A.size();
    vector<int> ans;
    int value=-1;
    int start=0;
    int end=n-1;
    int i=0;
    while(start<=end){
        int mid=(start+end)/2;
        if(A[mid]==x){
            value=mid;
            end=mid-1;
        }
        else if( A[mid]>x){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    ans.push_back(value);
    start=0;
    end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(A[mid]==x){
            value=mid;
            start=mid+1;
        }
        else if( A[mid]>x){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    ans.push_back(value);
    return ans;
}

int main(){
    vector<int> A={ 1, 3, 5, 5, 5, 5, 67, 123, 125 };
    vector<int> v2;
    v2=first_last_occurence(A, 5);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
}
