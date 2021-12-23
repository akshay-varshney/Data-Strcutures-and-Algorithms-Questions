// Stack: Maximum Rectangular Area in a Histogram
/*
 Input:
 N = 7
 arr[] = {6,2,5,4,5,1,6}
 Output: 12
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> S;

int maximum_Area(vector<int> &A){
    int n=A.size();
    int area=-1;
    int max_Area=-1;
    int i=0;
    while(i<n){
        if(S.empty() || A[i]>=A[S.top()]){
            S.push(i);
            i++;
        }
        else{
            int top=S.top();
            S.pop();
            if(S.empty()){
                area=A[top]*i;
            }
            else{
                area=A[top]*(i-S.top()-1);
            }
            max_Area=max(area,max_Area);
        }
    }
    while(!S.empty()){
        int top=S.top();
        S.pop();
        if(S.empty()){
            area=A[top]*i;
        }
        else{
            area=A[top]*(i-S.top()-1);
        }
        max_Area=max(max_Area,area);
    }
    return max_Area;
}



int main()
{
    vector<int> v1={6,2,5,4,5,1,6};
    cout<<maximum_Area(v1)<<endl;
}
