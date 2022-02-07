// Searching & Sorting: Product Array Puzzle
//https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#

#include<iostream>
#include<vector>

using namespace std;

vector<long long int> product_puzzle(vector<long long int> &A){
    int n=A.size();
    int value=0;
    long long int prod=1;
    for(int i=0;i<n;i++){
        if(A[i]!=0){
            prod*=A[i];
        }
        else{
            value++;
        }
    }
    vector<long long int> ans;
    for(int i=0;i<n;i++){
        if (value > 1) {
            ans.push_back(0);
        }
        else if (value == 0){
           ans.push_back(prod / A[i]);
        }

        else if (value == 1 && A[i] != 0) {
            ans.push_back(0);
        }
        else{
            ans.push_back(prod);
        }
    }
    return ans;
}
// Time: O(n) and Space: O(n)

int main(){
    vector<long long int> v1= {12,0,12};
    vector<long long int> v2;
    v2=product_puzzle(v1);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
    

}
