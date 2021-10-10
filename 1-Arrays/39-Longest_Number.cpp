// Array: Longest Number
// https://www.interviewbit.com/problems/largest-number/
/*
 [3, 30, 34, 5, 9],
  O/P is 9534330.
 */
#include<iostream>
#include<vector>

using namespace std;
bool comparision(string a, string b){
    string ab=a.append(b); //creating a AB string
    string ba=b.append(a);
    return ab.compare(ba)>0 ?1:0; // compare on basis of ascii value if ab>ba then it will return greater than 0
}

string largest_num(vector<int> &arr){
    int n=arr.size();
    vector<string> A;
    string value="";
    int _count0=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) _count0++;
        A.push_back(to_string(arr[i]));
    }
    sort(A.begin(), A.end(), comparision);
    if (_count0==A.size()) return "0";
    for(int i=0;i<n;i++){
        value+=A[i];
    }
    return  value;
}

int main(){
    vector<int> v1={472, 663, 964 };
    cout<<largest_num(v1)<<endl;
}
