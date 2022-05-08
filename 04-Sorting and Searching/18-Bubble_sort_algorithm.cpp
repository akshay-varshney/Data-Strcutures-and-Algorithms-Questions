// Searching & Sorting: Bubble Sort Algorithm

#include<iostream>
#include<vector>
using namespace std;

void bubblesort(vector<int> &A){
    int n=A.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
                swap(A[j+1],A[j]);
        }
    }
}

//Time: O(n2)

//Method 2: By using Recursion
void recursive_bubble_sort(vector<int> &A, int n){
    if(n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(A[i]>A[i+1]){
            swap(A[i], A[i+1]);
        }
    }
    recursive_bubble_sort(A, n-1);
}

int main(){
    vector<int> A={19,1,4,2,8,9};
    vector<int> B={19,1,4,2,8,9};
    bubblesort(A);
    recursive_bubble_sort(B, B.size());
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<B.size();i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;
}
