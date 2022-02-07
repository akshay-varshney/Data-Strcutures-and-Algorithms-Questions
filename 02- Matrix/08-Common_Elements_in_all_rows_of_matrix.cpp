// Matrix: Common elements in all rows of a given matrix
//https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1#
/*
 Mat=[[1,2,3,4],
 [2,2,-1,4]
 [7,9,7,4]
 [4,1,2,4]]
 Output:
 4
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> common_element(vector<vector<int>> &A){
    int n=A.size();
    int m=A[0].size();
    unordered_map<int, int> m1;
    vector<int> ans;
    for(int i=0;i<m;i++){
        m1.insert(std::make_pair(A[0][i],1));
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            unordered_map<int, int>::iterator iter=m1.find(A[i][j]);
            if(iter!=m1.end()){
                if(iter->second == i){
                    iter->second=i+1;
                    if(i==n-1 && iter->second== n){
                        ans.push_back(A[i][j]);
                    }
                }
            }
        }
    }
    return ans;
}
//Time: O(m*n) and Space:O(m)

int main(){
    vector<vector<int>> v1={
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
    vector<int> v2;
    v2=common_element(v1);
    for(auto it=v2.begin();it!=v2.end();it++){
        cout<<*it<<endl;
    }
}
