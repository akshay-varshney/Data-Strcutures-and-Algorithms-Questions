// Array: Kth Row of Pascal's Triangle
// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
/*
 Input>k=3
 1
 1 1
 1 2 1
 1 3 3 1
 O/p: 1 3 3 1 
 */
#include<iostream>
#include<vector>

using namespace std;

vector<int> pascal_traingle(int n){
    vector<int> result;
    vector<int> temp;
    if (n<0) return {};
    result.push_back(1);
    if (n==0) return  result;
    result.push_back(1);
    if(n==1) return result;
    temp=result;
    result={};
    for(int i=1;i<n;i++){
        result.push_back(1);
        for(int i=0;i<temp.size()-1;i++){
            int val=temp[i]+temp[i+1];
            result.push_back(val);
        }
        result.push_back(1);
        temp=result;
        result={};
    }
    return temp;
}

int main(){
    vector<int> v1={5,4,3,1,6,1,7,10};
    vector<int> v2;
    v2=pascal_traingle(5);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<endl;
    }
}
