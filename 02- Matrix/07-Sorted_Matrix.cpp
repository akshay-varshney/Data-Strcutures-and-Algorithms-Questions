// Matrix: Sorted Matrix
//https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1#
/*
 Mat=[[10,20,30,40],
 [15,25,35,45]
 [27,29,37,48]
 [32,33,39,50]]
 Output:
 10 15 20 25
 27 29 30 32
 33 35 37 39
 40 45 48 50
 */
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> sortedArix(int n, vector<vector<int>> &A) {
    vector<int> temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            temp.push_back(A[i][j]);
        }
    }
    std::sort(temp.begin(), temp.end());
    int k=0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            A[i][j] = temp[k++];
        }
    }
    return A;
}

int main(){
    vector<vector<int>> v1={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    vector<vector<int>> v2;
    v2=sortedArix(v1.size(), v1);
    for(auto it=0;it<v2.size();it++){
        for(auto it1=0;it1<v2[0].size();it1++){
            cout<< v2[it][it1] <<" ";
        }
    }
}
