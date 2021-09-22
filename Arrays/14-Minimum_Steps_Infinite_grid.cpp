// Array: Min Steps in Infinite Grid
// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

#include<vector>
#include<iostream>

using namespace std;

//minimum number of steps to reach the end of the array
int steps(vector<int> &A, vector<int> &B){
    int steps=0;
       int first, second;
       for(int i=0;i<A.size()-1;i++){
           first=abs(A[i]-A[i+1]);
           second=abs(B[i]-B[i+1]);
           steps+=max(first,second);
       }
       return steps;
}

int main(){
    vector<int> v1={1,-2,4,5};
    vector<int> v2={1,1,3,2};
    cout<<"Minimum Steps: "<<steps(v1, v2)<<endl;
}
