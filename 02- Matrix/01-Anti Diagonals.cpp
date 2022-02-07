// Matrix: Anti Diagonals
// https://www.interviewbit.com/problems/anti-diagonals/
/*
 Input>
 1 2 3
 4 5 6
 7 8 9
 
 O/p:
 [
   [1],
   [2, 4],
   [3, 5, 7],
   [6, 8],
   [9]
 ]
 */
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> diagonal(vector<vector<int>> &A ){
    int n=A.size();
    vector<vector<int>> ans;
    vector<int> temp;
    //upper triangle traversal
    for(int i=0;i<n;i++){
        int r=0,c=i;
        while(c>=0){
            temp.push_back(A[r][c]);
            r++;
            c--;
        }
        ans.push_back(temp);
        temp={};
    }
    //lower triangle traversal
    for(int i=1;i<n;i++){
        int r=i,c=n-1;
        while(r<n){
            temp.push_back(A[r][c]);
            r++;
            c--;
        }
        ans.push_back(temp);
        temp={};
    }
    temp.clear();
    return ans;
}

int main(){
    vector<vector<int>> v1={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> v2;
    v2=diagonal(v1);
    for(auto i=0;i<v2.size();i++){
        for(int j=0;j<v2[i].size();j++){
            cout<< v2[i][j]<<" ";
        }
        cout<<endl;
    }
}
