// Stack: Find the next smaller Elment
//https://www.interviewbit.com/problems/nearest-smaller-element/
/*
 Input:
 Input 1:
     A = [4, 5, 2, 10, 8]
 Output 1:
     G = [-1, 4, -1, 2, 2]
 
 */

#include <iostream>
#include <vector>
#include<stack>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    int n=A.size();
    stack<int> S;
    vector<int> smaller(n,-1);
    int i=0;
    while(i<n)
    {
        if(S.empty())
        {
            S.push(i);
            i++;
        }
        else if(A[S.top()]>A[i])
            S.pop();
        else
        {
            int x = S.top();
            smaller[i]=A[x];
            S.push(i);
            i++;
        }
    }
    return smaller;
}

int main(){
    vector<int> v1={34, 35, 27, 42, 5, 28, 39, 20, 28};
    auto v2= prevSmaller(v1);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
