// Searching:Find the repeating and the missing

/*
 I/p: {3,1,3}
 o/p: 3,2
 */
#include<iostream>
#include<vector>
using namespace std;

vector<int> duplicate_nissing(vector<int> &A){
    vector<int> ans;
    int n=A.size();
    int i=0;
    while(i<n){
        if(A[i]==i+1){
            i++;
        }
        else if (A[i]!=A[A[i]-1]){
            swap(A[i],A[A[i]-1]);
        }
        else{
            i++;
        }
    }
    for(int i=0;i<n;i++){
        if(A[i]==i+1){
            continue;
        }
        else{
            ans.push_back(A[i]); //duplicate
            ans.push_back(i+1); //missing
        }
    }
    return ans;
}

int main(){
    vector<int> v1= {4,3,6,2,1,1};
    vector<int> v2;
    v2=duplicate_nissing(v1);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<endl;
    }
    
}
