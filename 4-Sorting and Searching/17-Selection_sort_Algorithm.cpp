// Searching & Sorting: Selection Sort Algorithm

#include<iostream>
#include<vector>
using namespace std;

void selectionsort(vector<int> &A){
    int n=A.size();
    int mini=INT_MAX;
    int index=0;
    for(int i=0;i<n-1;i++){
        index=i;
        for(int j=i+1;j<n;j++){
//            int index=j;
            if(A[index]>A[j]){
                index=j;
            }
        }
        swap(A[i],A[index]);
    }
}

//Time: O(n2)

int main(){
    vector<int> A={64, 25, 12, 22, 11};
    selectionsort(A);
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<endl;
    }
   
}
