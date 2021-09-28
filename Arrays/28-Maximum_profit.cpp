// Array: Maximum profit by buying and selling a share at most twice
// https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/
#include<iostream>
#include<vector>

using namespace std;
int maximum_profit(vector<int> A){
    int n=A.size();
    if (n<=1) return 0;
    int mini=A[0];
    int mini2=A[1];
    int ind1=0;
    int ind2=1;
    //finding the first and second minimum in array
    for(int i=1;i<n;i++){
        if(A[i]<mini){
            if(mini2>mini){
                mini2=mini;
                ind2=ind1;
            }
            mini=A[i];
            ind1=i;
        }
        else if(A[i]<mini2){
            mini2=A[i];
            ind2=i;
        }
    }
    int val1=max(ind1,ind2);
    int val2=min(ind1,ind2);
    int profit1=0;
    for(int i=val2;i<val1-1;i++){
        profit1=max(profit1,A[i+1]-A[val2]);
    }
    int summed=profit1;
    profit1=0;
    for(int i=val1;i<n-1;i++){
        profit1=max(profit1,A[i+1]-A[val1]);
    }
    summed+=profit1;
    return summed;
}

int main(){
    vector<int> v1={2, 30, 15, 10, 8, 25, 80};
    cout<<maximum_profit(v1)<<endl;
}
