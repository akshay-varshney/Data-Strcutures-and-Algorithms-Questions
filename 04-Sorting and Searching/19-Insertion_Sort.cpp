// Searching & Sorting: Bubble Sort Algorithm

#include<iostream>
#include<vector>
using namespace std;

void insertionsort(vector<int> &A){
    bool flag=false;
    int n=A.size();
    for(int i=1;i<n;i++){
        int key=A[i];
        int j=i-1;
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
        }
    }


//Time: O(n2)

//Method 2: By using Recursion
void recursive_insertion_sort(vector<int> &A, int n){
    if (n <= 1){
        return;
    }
    recursive_insertion_sort(A, n-1);
    int last =A[n-1];
    int j = n-2;
    while (j >= 0 && A[j] > last)
    {
        A[j+1] = A[j];
        j--;
    }
    A[j+1] = last;
}

int main(){
    vector<int> A={19,1,4,2,8,9};
    vector<int> B={19,1,4,2,8,9};
    insertionsort(A);
    recursive_insertion_sort(B, B.size());
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<B.size();i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;
}
